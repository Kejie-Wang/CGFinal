
#include "object.h" 

map<string, Object> objmap;
set<string> objname;
string cd;
map<string, Material> matname;
GLfloat dx = 0, dy = 0, dz = 0;
GLfloat ax = 0, ay = 0, az = 0;
GLint mx = 0, my = 0;
GLint MouseDown = 0;
GLfloat aspect = 1;
void myIdle()
{
	Sleep(10);
	glutPostRedisplay();
}

void myReshap1e(int width, int height)
{
	aspect = (float)width / (height ? height : 1);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, aspect, 1, 10000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void setLight()
{
	static const GLfloat light_position[] = { 50.0f, 50.0f, 50.0f, 0.0f };
	static const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	static const GLfloat light_diffuse[] = { 1.0f, 0.9f, 0.9f, 0.0f };
	static const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
	static const GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0f);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 120.0f);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void tank::setMaterial(Material &mat)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat.specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat.emission);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);
}

void tank::drawtank()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(dx, dy - 20, dz - 100);
	glRotatef(ax, 1.0f, 0.0f, 0.0f);
	glRotatef(ay, 0.0f, 1.0f, 0.0f);
	//glScalef(0.2,0.2,0.2);
	for (set<string>::iterator it = objname.begin(); it != objname.end(); ++it)
	{
		Object temp = objmap[*it];
		setMaterial(matname[temp.material]);
		glBindTexture(GL_TEXTURE_2D, matname[temp.material].map);
		if (temp.row == 3) glBegin(GL_TRIANGLES);
		else glBegin(GL_QUADS);
		vector<int>::iterator iter = temp.faces.begin();
		if (temp.col == 1)
		{
			while (iter != temp.faces.end())
			{
				glVertex3f(temp.vertexs[*iter - 1].x, temp.vertexs[*iter - 1].y, temp.vertexs[*iter - 1].z);
				++iter;
			}
		}
		else if (temp.col == 2)
		{
			while (iter != temp.faces.end())
			{
				glTexCoord2f(temp.texcoords[*(iter + 1) - 1].first, temp.texcoords[*(iter + 1) - 1].second);
				glVertex3f(temp.vertexs[*iter - 1].x, temp.vertexs[*iter - 1].y, temp.vertexs[*iter - 1].z);
				iter += 2;
			}
		}
		else if (temp.col == 3 && !temp.texcoords.empty())
		{
			while (iter != temp.faces.end())
			{
				glNormal3f(temp.normals[*(iter + 2) - 1].x, temp.normals[*(iter + 2) - 1].y, temp.normals[*(iter + 2) - 1].z);
				glTexCoord2f(temp.texcoords[*(iter + 1) - 1].first, temp.texcoords[*(iter + 1) - 1].second);
				glVertex3f(temp.vertexs[*iter - 1].x, temp.vertexs[*iter - 1].y, temp.vertexs[*iter - 1].z);
				iter += 3;
			}
		}
		else
		{
			while (iter != temp.faces.end())
			{
				glNormal3f(temp.normals[*(iter + 2) - 1].x, temp.normals[*(iter + 2) - 1].y, temp.normals[*(iter + 2) - 1].z);
				glVertex3f(temp.vertexs[*iter - 1].x, temp.vertexs[*iter - 1].y, temp.vertexs[*iter - 1].z);
				iter += 3;
			}
		}
		glBindTexture(GL_TEXTURE_2D, 0);
		glEnd();
	}
	glPopMatrix();
	glutSwapBuffers();
}


GLuint load_texture(const char *file_name)
{
	GLint width, height, total_bytes;
	GLuint last_texture_ID, texture_ID = 0;
	GLubyte *pixels = NULL;
	FILE *pFile;

	if ((pFile = fopen(file_name, "rb")) == NULL)
	{
		cout << "Read texture error" << endl;
		return 0;
	}

	fseek(pFile, 18, SEEK_SET);
	fread(&width, sizeof(width), 1, pFile);
	fread(&height, sizeof(height), 1, pFile);
	fseek(pFile, 54, SEEK_SET);

	total_bytes = (width * 3 + (4 - width * 3 % 4) % 4)*height;

	if ((pixels = (GLubyte *)malloc(total_bytes)) == NULL)
	{
		fclose(pFile);
		return 0;
	}

	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	{
		GLint max;
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);
		if (!power_of_two(width) || !power_of_two(height) || width>max || height>max)
		{
			const GLint new_width = 1024;
			const GLint new_height = 1024;
			GLint new_total_bytes;
			GLubyte *new_pixels = NULL;

			new_total_bytes = (new_width * 3 + (4 - new_width * 3 % 4) % 4)*new_height;
			new_pixels = (GLubyte *)malloc(new_total_bytes);
			if (new_pixels == NULL)
			{
				free(pixels);
				fclose(pFile);
				return 0;
			}

			gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels, new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);

			free(pixels);
			pixels = new_pixels;
			width = new_width;
			height = new_height;
		}
	}

	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}

	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint *)&last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	free(pixels);
	fclose(pFile);
	return texture_ID;
}

void ReadMtl(string &cd, string mtlfile, map<string, Material> &mat)
{
	ifstream in;
	string line, word, ptname, ntname, fname;
	unsigned map;
	bool hasmap = false;
	float ambient[3] = { 0.0, 0.0, 0.0 };
	float diffuse[3] = { 0.0, 0.0, 0.0 };
	float specular[3] = { 0.0, 0.0, 0.0 };
	float emission[3] = { 0.0, 0.0, 0.0 };

	in.open((cd + "\\" + mtlfile).c_str());
	if (!in)
	{
		cout << "Read mtl error !" << endl;
		return;
	}
	while (getline(in, line))
	{
		if (line.size() == 0 || line[0] == '#') continue;
		istringstream is(line);
		is >> word;
		if (word == "newmtl")
		{
			is >> ntname;
			if (!ptname.empty())
			{
				if (hasmap)
				{
					mat.insert(make_pair(ptname, Material(ambient, diffuse, specular, emission, map)));
				}
				else
				{
					mat.insert(make_pair(ptname, Material(ambient, diffuse, specular, emission, 0)));
				}
			}
			ptname = ntname;
			hasmap = false;
		}
		else if (word == "Ka")
		{
			is >> ambient[0] >> ambient[1] >> ambient[2];
		}
		else if (word == "Kd")
		{
			is >> diffuse[0] >> diffuse[1] >> diffuse[2];
		}
		else if (word == "Ks")
		{
			is >> specular[0] >> specular[1] >> specular[2];
		}
		else if (word == "Ke")
		{
			is >> emission[0] >> emission[1] >> emission[2];
		}
		else if (word == "map_Ka")
		{
			is >> fname;
			map = load_texture((cd + "\\" + fname).c_str());
			hasmap = true;
		}
	}
	if (!ntname.empty())
	{
		if (hasmap)
		{
			mat.insert(make_pair(ptname, Material(ambient, diffuse, specular, emission, map)));
		}
		else
		{
			mat.insert(make_pair(ptname, Material(ambient, diffuse, specular, emission, 0)));
		}
	}
	in.close();
}

void ReadObj(string &cd, string file, map<string, Object> &m, set<string> &n, map<string, Material> &matname)
{
	ifstream in;
	vector<VERTEX> vertexs;
	vector< pair<float, float> > texcoords;
	vector<VERTEX> normals;
	vector<int> faces;
	int row = 0, col = 0;
	string line, word, goname, mtlname;
	char Buffer[MAX_PATH];

	if (file.find(":") != string::npos)
	{
		cd = string(file.begin(), file.begin() + file.rfind("\\"));
	}
	else if (startswith(file, string(".\\")))
	{
		GetCurrentDirectoryA(MAX_PATH, Buffer);
		cd = Buffer + string(file.begin() + 1, file.begin() + file.rfind("\\"));
	}
	else if (startswith(file, string("..\\")))
	{
		GetCurrentDirectoryA(MAX_PATH, Buffer);
		cd = Buffer;
		cd = string(cd.begin(), cd.begin() + cd.rfind("\\"));
		cd = cd + string(file.begin() + 2, file.begin() + file.rfind("\\"));
		cout << cd << endl;
	}
	else
	{
		GetCurrentDirectoryA(MAX_PATH, Buffer);
		if (file.rfind("\\") != string::npos)
		{
			cd = Buffer + string("\\") + string(file.begin(), file.begin() + file.rfind("\\"));
		}
		else
		{
			cd = Buffer;
		}
	}

	in.open(file.c_str());
	if (!in)
	{
		cout << "Read obj error !" << endl;
		exit(0);
	}
	while (getline(in, line))
	{
		if (line.size() == 0 || line[0] == '#') continue;
		istringstream is(line);
		is >> word;
		if (word == "v")
		{
			VERTEX p;
			is >> p.x >> p.y >> p.z;
			vertexs.push_back(p);
		}
		else if (word == "vt")
		{
			pair<float, float> p;
			is >> p.first >> p.second;
			texcoords.push_back(p);
		}
		else if (word == "vn")
		{
			VERTEX p;
			is >> p.x >> p.y >> p.z;
			normals.push_back(p);
		}
		else if (word == "o" || word == "g")
		{
			if (!goname.empty() && !faces.empty())
			{
				Object obj(vertexs.begin(), vertexs.end(), texcoords.begin(), texcoords.end(), normals.begin(), normals.end(), faces.begin(), faces.end(), row, col, mtlname);
				while (n.count(goname) != 0)
				{
					goname.push_back('0');
				}
				m.insert(make_pair(goname, obj));
				n.insert(goname);
				faces.clear();
			}
			is >> goname;
		}
		else if (word == "f")
		{
			int r = 0, c = 0;
			while (is >> word)
			{
				c = count(word.begin(), word.end(), '/');
				if (c == 0)
				{
					faces.push_back(atoi(word.c_str()));
				}
				else if (c == 1)
				{
					faces.push_back(atoi(string(word.begin(), word.begin() + word.find("/")).c_str()));
					faces.push_back(atoi(string(word.begin() + word.find("/") + 1, word.end()).c_str()));
				}
				else if (c == 2)
				{
					int a = word.find("/");
					int b = word.find("/", a + 1);
					faces.push_back(atoi(string(word.begin(), word.begin() + a).c_str()));
					faces.push_back(atoi(string(word.begin() + a + 1, word.begin() + b).c_str()));
					faces.push_back(atoi(string(word.begin() + b + 1, word.end()).c_str()));
				}
				++r;
			}
			row = r;
			col = c + 1;
		}
		else if (word == "mtllib")
		{
			is >> word;
			ReadMtl(cd, word, matname);
		}
		else if (word == "usemtl")
		{
			is >> mtlname;
		}
	}
	if (!goname.empty() && !faces.empty())
	{
		Object obj(vertexs.begin(), vertexs.end(), texcoords.begin(), texcoords.end(), normals.begin(), normals.end(), faces.begin(), faces.end(), row, col, mtlname);
		while (n.count(goname) != 0)
		{
			goname.push_back('0');
		}
		m.insert(make_pair(goname, obj));
		n.insert(goname);
		faces.clear();
	}
	in.close();
}


void init()
{
	ReadObj(cd, ".\\tank\\tank.obj", objmap, objname, matname);
	//glutFullScreen();
	glClearColor(0.93, 0.94, 0.98, 1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//setLight();
}


