#ifndef APPLOGIC_H
#define APPLOGIC_H
#include "entry_point.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <vector>

#include <QList>
#include <QFile>
#include <QStandardItemModel>
#define APPLOGIC_H



// Перечисление доступных функций, выделенных в сегрегированный файл логики


void getDataFromFile(Input* input,
                     Output* output
                     );
void solve(Input* input,
           Output* output);

#endif // APPLOGIC_H
