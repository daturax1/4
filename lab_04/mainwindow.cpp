#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gl_view.h"

#include <iostream>

#include <QPainter>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pGlView = new GLView(this);
    ui->glLayout -> addWidget(pGlView);

    connect(ui->dialRotX, SIGNAL(valueChanged(int)), pGlView, SLOT(changeXang(int)));
    ui->dialRotX->setValue(110);
    connect(ui->dialRotY, SIGNAL(valueChanged(int)), pGlView, SLOT(changeYang(int)));
    ui->dialRotY->setValue(180);
    connect(ui->dialRotZ, SIGNAL(valueChanged(int)), pGlView, SLOT(changeZang(int)));
    ui->dialRotZ->setValue(160);

    connect(ui->minX, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMinX(double)));
    connect(ui->maxX, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMaxX(double)));
    connect(ui->minY, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMinY(double)));
    connect(ui->maxY, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMaxY(double)));
    connect(ui->minZ, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMinZ(double)));
    connect(ui->maxZ, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMaxZ(double)));

    ui->minX->setValue(-0.7);
    ui->maxX->setValue(0.7);
    ui->minY->setValue(-2);
    ui->maxY->setValue(1);
    ui->minZ->setValue(-0.1);
    ui->maxZ->setValue(0.7);

    connect(ui->minNormal, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMinNormal(double)));
    connect(ui->maxNormal, SIGNAL(valueChanged(double)), pGlView, SLOT(changeMaxNormal(double)));
//    connect(ui->normalize, &QPushButton::clicked, this, &MainWindow::normFunction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::normFunction() {

}

//Преобразование массива строк в формат QStringList
QStringList ConvertRowToQTFormat(std::vector<std::string> strings) {
    QStringList qsl;

    for(size_t i = 0; i < strings.size(); i++) {
        qsl.append(QString::fromStdString(strings[i]));
    }

    return qsl;
}

void MainWindow::updateDataFunction(
        const std::vector<std::vector<std::string>>& data)
{
    pGlView->updateData(data);
}


//Эта функция вызывается при нажатии на кнопку "Открыть таблицу"
void MainWindow::on_OpenButton_clicked()
{
    //Открытие диалогового окна (Допускаем к открытию только csv файлы)
    QString pathFileName = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "CSV File (*.csv)");
    //Вывод полного имени файла на экран
    ui->FilePathLabel->setText(pathFileName);
    if (pathFileName.isEmpty())
        return;
    else
    {

        Input input;
        input.funcType = FuncType::getData;
        input.filename = pathFileName.toStdString();
        Output output;
        entryPoint(&input, &output);
        //Выводим на экран данные
        updateDataFunction(output.data);
    }
}
