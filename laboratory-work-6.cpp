#include <iostream>
#include <locale>
#include "Functions.h"

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    string file_name = argv[2];
    string mode = argv[1];
    string type = argv[3];
    if (mode == "write")
    {
        write(file_name, type);
    }
    else if (mode == "read")
    {
        cout << "------------------------------------------" << endl;
        vector<Bus> result;
        result = read(file_name, type);
        for (int i = 0; i < result.size(); i++)
        {
            cout << "Модель: " << result[i].model << endl;
            cout << "Длина: " << result[i].lenght << endl;
            cout << "Высота: " << result[i].height << endl;
            cout << "Максимальное число пассажиров: " << result[i].max_passengers << endl;
            cout << "Среднее число пассажиров: " << result[i].avg_passengers << endl;
            cout << "------------------------------------------" << endl;
        }
    }
    else if (mode == "clear")
    {
        clear(file_name, type);
    }
}
