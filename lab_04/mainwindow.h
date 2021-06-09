#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QtAlgorithms>
#include <QVector>
#include <QDebug>

#include <string>
#include <functional>

#include "applogic.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class GLView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    GLView *pGlView;

private slots:

    void on_OpenButton_clicked();

//    void on_CalculateButton_clicked();

private:
    Ui::MainWindow *ui;

    void updateDataFunction(const std::vector<std::vector<std::string>>& data);
    std::vector<std::vector<std::string>> getDataFromTable();
};
#endif // MAINWINDOW_H
