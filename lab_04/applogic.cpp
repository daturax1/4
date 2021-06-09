#include "applogic.h"

#include <sstream>
#include <fstream>

#include <QtDebug>

#include <QMessageBox>
#include <iostream>

void getDataFromFile(Input* input,
                     Output* output
                     )
{
    std::ifstream source(input->filename);
    std::string currentLine;

    while (std::getline(source, currentLine)) {
        std::stringstream oneLineStream(currentLine);
        std::vector<std::string> record;
        std::string oneValue;
        while (std::getline(oneLineStream, oneValue, ',')) {
           record.push_back(oneValue);
        }
        output->data.push_back(record);
    }
}
