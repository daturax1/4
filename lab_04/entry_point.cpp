#include "applogic.h"

// Определение точки входа
void entryPoint(Input* input, Output* output)
{
    switch(input->funcType)
    {
        case FuncType::getData:
            getDataFromFile(input, output);
            break;
        default:
            break;
    }
}
