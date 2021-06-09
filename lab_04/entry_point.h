#ifndef ENTRY_POINT_H
#include <iostream>
#include <vector>

#define ENTRY_POINT_H


using namespace std;

// Перечисление доступных функций, выделенных в сегрегированный файл логики
enum FuncType
{
    getData,                                    // функция чтения данных из csv файла
    calculateData,                              // функция для вычислений
};

struct Input {
    std::string filename;
    std::vector<std::vector<std::string>> data;
    std::string regionName;
    FuncType funcType;
};

struct PointData {
    double year;
    double value;
};

struct Output {
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> solution;
    std::vector<PointData> toDraw;
    size_t fields_num;
    double minValue = 0.0;
    double maxValue = 0.0;
    double midValue = 0.0;
};

// Объявление точки входа
void entryPoint(Input* input, Output* output);

#endif // ENTRY_POINT_H
