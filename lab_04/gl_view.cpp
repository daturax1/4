#include "gl_view.h"
#include "mainwindow.h"
#include <cmath>

GLView::GLView(MainWindow* parent):
    QGLWidget(parent) {
}

void
GLView::initializeGL() {
    glEnable(GL_DEPTH_TEST);
//     glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);

    glEnable(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    //    glClearColor(100, 0, 0, 1);
    //    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat specularMat[] = {0.3, 0.7, 0.1, 1.0};
    GLfloat emissionMat[] = {0.0, 0.0, 0.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);
    glMaterialfv(GL_FRONT, GL_EMISSION, emissionMat);
    {
        glEnable(GL_LIGHT0); //координаты фонариков

        float vposx = 0.0, vposy = 0.0, vposz = -30.0;
        float m = -1.0;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.6, 0.6, 0.9, 1.0}; //blue
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);
    }

    {
        glEnable(GL_LIGHT1);

        // (-30,   0,   0) - right
        // (  0, -30,   0) - up
        // (  0,   0, -30) - front
        float vposx = -30.0, vposy = -20.0, vposz = 30.0;
        float m = -1.0;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.9, 0.6, 0.6, 1.0};
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT1, GL_POSITION, pos);
        glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
    }


    {
        glEnable(GL_LIGHT2);

        //         (-30,   0,   0) - right
        //         (  0, -30,   0) - up
        //         (  0,   0, -30) - front
        float vposx =30.0, vposy = -20.0, vposz = 30.0;
        float m;
        float vdirx = vposx * m, vdiry = vposy * m, vdirz = vposz * m;
        float r = std::sqrt(vdirx*vdirx + vdiry*vdiry + vdirz*vdirz);
        vdirx /= r; vdiry /= r; vdirz /=r;

        GLfloat ambientLight[] = {0.0, 0.0, 0.0, 1.0};
        GLfloat diffuseReflection[] = {0.6, 0.6, 0.9, 1.0};
        GLfloat specularLight[] = {0.2, 0.2, 0.2, 1.0};
        GLfloat pos[] = {GLfloat(vposx),  GLfloat(vposy), GLfloat(vposz), 1};
        GLfloat dir[] = {GLfloat(vdirx),  GLfloat(vdiry), GLfloat(vdirz)};

        glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseReflection);
        glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight);
        glLightfv(GL_LIGHT2, GL_POSITION, pos);
        glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir);
    }
}

void
GLView::resizeGL(int w, int h){
  int s = qMin(w, h);
  glViewport((w - s) / 2, (h - s) / 2, s, s);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-0.25, 0.25, -0.25, 0.25, -1, 1);
  glMatrixMode(GL_MODELVIEW);
}

void
GLView::paintGL(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glRotated(xang, 1.0, 0.0, 0.0);
  glRotated(yang, 0.0, 1.0, 0.0);
  glRotated(zang, 0.0, 0.0, 1.0);

  glPushAttrib(GL_CURRENT_BIT);
  glBegin(GL_LINES);{
    //Coordinate system
    glNormal3d(0, 0, 1);
    glColor3f(3.0, .0, 0.0);
    glVertex3f(-0.3, 0.0, 0.0);
    glVertex3f( 1.0, 0.0, 0.0);

    glNormal3d(1.0, 0, 0);
    glColor3f(0.0, 3.0, 0.0);
    glVertex3f(0.0, -0.3, 0.0);
    glVertex3f(0.0,  1.0, 0.0);

    glNormal3d(0, 1, 0);
    glColor3f(0.0, 0.0, 3.0);
    glVertex3f( 0.0, 0.0, -0.3);
    glVertex3f( 0.0, 0.0,  1.0);
  }glEnd();

//  glBegin(GL_TRIANGLES); {
//      glNormal3d(0, 0, -1);
//      glVertex3d(0, 0, 0);
//      glVertex3d(10, 0, 0);
//      glVertex3d(10, 10, 0);
//  } glEnd();


  glBegin(GL_TRIANGLES); {
      int h = data3d.size();
      if(h) {
          int w = data3d[0].size();


          double minzv, maxzv;
          bool first = true;
          for (int p = 0; p < h - 1; p++) {
              for (int q = 0; q < w - 1; q++) {
                  if (first || minzv > data3d[p][q]) {
                      minzv = data3d[p][q];
                  }
                  if (first || maxzv < data3d[p][q]) {
                      maxzv = data3d[p][q];
                  }
                  first = false;
              }
          }

          for (int p = 0; p < h - 1; p++) {
              for (int q = 0; q < w - 1; q++) {
                  {
                      //                    double x1 = mx * q, y1 = my * p, z1 = (data3d[p][q] - minzv) / (maxzv - minzv);
                      double x1 = minX + (maxX - minX) * (q / (w - 1.0)),
                              y1 = minY + (maxY - minY) * (p / (h - 1.0)),
                              z1 = minZ + (maxZ - minZ) * (data3d[p][q] - minzv) / (maxzv - minzv);
                      //                    double x2 = mx * (q+1), y2 = my * p, z2 =(m*data3d[p][q+1] - minzv) / (maxzv - minzv);
                      double x2 = minX + (maxX - minX) * (q+1.0) / (w - 1.0),
                              y2 = minY + (maxY - minY) * p / (h - 1.0),
                              z2 = minZ + (maxZ - minZ) * (data3d[p][q+1] - minzv) / (maxzv - minzv);
                      //                    double x3 = mx* 1, y3 = my * (p + 1), z3 = (m*data3d[p+1][q] - minzv) / (maxzv - minzv);
                      double x3 = minX + (maxX - minX) * q / (w - 1.0),
                              y3 = minY + (maxY - minY) * (p + 1.0) / (h - 1.0),
                              z3 = minZ + (maxZ - minZ) * (data3d[p+1][q] - minzv) / (maxzv - minzv);

                      double dx1 = x2 - x1, dy1 = y2 - y1, dz1 = z2 - z1;
                      double dx2 = x3 - x1, dy2 = y3 - y1, dz2 = z3 - z1;
                      double nx = dy1 * dz2 - dy2 * dz1;
                      double ny = dz1 * dx2 - dz2 * dx1;
                      double nz = dx1 * dy2 - dy1 * dx2;
                      double r = std::sqrt(nx * nx + ny * ny + nz * nz);
                      nx /= r; ny /= r; nz /= r;

                      glNormal3d(nx, ny, nz);

                      glVertex3d(x1, y1, z1);
                      glVertex3d(x2, y2, z2);
                      glVertex3d(x3, y3, z3);
                  }
                  {
                      //                    double x1 = mx * (q + 1), y1 = my * p, z1 = (data3d[p][q+1] - minzv) / (maxzv - minzv);
                      double x1 = minX + (maxX - minX) * ((q + 1.0) / (w - 1.0)),
                              y1 = minY + (maxY - minY) * (p / (h - 1.0)),
                              z1 = minZ + (maxZ - minZ) * (data3d[p][q+1] - minzv) / (maxzv - minzv);
                      //                    double x2 = mx * (q+1), y2 = my * (p+1), z2 = (data3d[p+1][q+1] - minzv) / (maxzv - minzv);
                      double x2 = minX + (maxX - minX) * (q+1.0) / (w - 1.0),
                              y2 = minY + (maxY - minY) * (p+1.0) / (h - 1.0),
                              z2 = minZ + (maxZ - minZ) * (data3d[p+1][q+1] - minzv) / (maxzv - minzv);
                      //                    double x3 = mx * q, y3 = my * (p+1), z3 = (data3d[p+1][q] - minzv) / (maxzv - minzv);
                      double x3 = minX + (maxX - minX) * q / (w - 1.0),
                              y3 = minY + (maxY - minY) * (p + 1.0) / (h - 1.0),
                              z3 = minZ + (maxZ - minZ) * (data3d[p+1][q] - minzv) / (maxzv - minzv);

                      double dx1 = x2 - x1, dy1 = y2 - y1, dz1 = z2 - z1;
                      double dx2 = x3 - x1, dy2 = y3 - y1, dz2 = z3 - z1;
                      double nx = dy1 * dz2 - dy2 * dz1;
                      double ny = dz1 * dx2 - dz2 * dx1;
                      double nz = dx1 * dy2 - dy1 * dx2;
                      double r = std::sqrt(nx * nx + ny * ny + nz * nz);
                      nx /= r; ny /= r; nz /= r;

                      glNormal3d(nx, ny, nz);
                      glVertex3d(x1, y1, z1);
                      glVertex3d(x2, y2, z2);
                      glVertex3d(x3, y3, z3);
                  }
              }
          }
      }
  }glEnd();

  glPopAttrib();
}

void
GLView::changeXang(int xang_) {
    xang = xang_;
    updateGL();
}

void
GLView::changeYang(int yang_) {
    yang = yang_;
    updateGL();
}

void
GLView::changeZang(int zang_) {
    zang = zang_;
    updateGL();
}

void
GLView::changeMinX(double minX_) {
    minX = minX_;
    updateGL();
}

void
GLView::changeMaxX(double maxX_) {
    maxX = maxX_;
    updateGL();
}

void
GLView::changeMinY(double minY_) {
    minY = minY_;
    updateGL();
}

void
GLView::changeMaxY(double maxY_) {
    maxY = maxY_;
    updateGL();
}

void
GLView::changeMinZ(double minZ_) {
    minZ = minZ_;
    updateGL();
}

void
GLView::changeMaxZ(double maxZ_) {
    maxZ = maxZ_;
    updateGL();
}

void
GLView::changeMinNormal(double minNormal_) {
    minNormal = minNormal_;
    updateGL();
}

void
GLView::changeMaxNormal(double maxNormal_) {
    maxNormal = maxNormal_;
    updateGL();
}


void
GLView::updateData(const std::vector<std::vector<std::string>> &stringData) {
    std::vector<std::vector<double>> data3d;
    for(const auto& strRow: stringData) {
        std::vector<double> row;
        for(const auto& element: strRow) {
            row.push_back(atof(element.c_str()));
        }
        data3d.push_back(row);
    }
    this->data3d.swap(data3d);
    updateGL();
}
