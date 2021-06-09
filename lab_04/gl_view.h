#ifndef GL_VIEW_H
#define GL_VIEW_H

#include <QWidget>

class MainWindow;

class GLView: public QWidget {
    Q_OBJECT
public:
    GLView(MainWindow * = 0);

    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

    void updateData(const std::vector<std::vector<std::string>>&);
public slots:
    void changeXang(int);
    void changeYang(int);
    void changeZang(int);
    void changeMinX(double);
    void changeMaxX(double);
    void changeMinY(double);
    void changeMaxY(double);
    void changeMinZ(double);
    void changeMaxZ(double);
    void changeMinNormal(double);
    void changeMaxNormal(double);
private:
    int xang;
    int yang;
    int zang;
    double minX;
    double maxX;
    double minY;
    double maxY;
    double minZ;
    double maxZ;
    double minNormal;
    double maxNormal;

    std::vector<std::vector<double>> data3d;
};

#endif
