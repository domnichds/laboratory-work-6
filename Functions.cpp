#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstring>
#include "Functions.h"

using namespace std;

vector<Bus> generate_struct(int number_of_struct)
{
    vector<Bus> result;
    srand(time(0));
    map<int, string> busMap =
    {
        {0, "ЛиАЗ-677"}, {1, "ПАЗ-3205"}, {2, "КАВЗ-685"}, {3, "Икарус-250"},
        {4, "РАФ-2203"}, {5, "ГАЗ-03-30"}, {6, "ЗиС-155"}, {7, "ЗиЛ-158"},
        {8, "КАвЗ-3270"}, {9, "МАЗ-103"}, {10, "НефАЗ-5299"}, {11, "Икарус-280"},
        {12, "ПАЗ-672"}, {13, "ЛАЗ-695"}, {14, "МАРЗ-5266"}, {15, "ЗиС-154"},
        {16, "ЛиАЗ-5256"}, {17, "ЛАЗ-699Р"}, {18, "ПАЗ-4234"}, {19, "ЛАЗ-4202"},
        {20, "ПАЗ-652"}, {21, "ЗиЛ-127"}, {22, "ЛиАЗ-5292"}, {23, "ГАЗель Next"},
        {24, "ЮМЗ-Т1"}, {25, "Таджикистан-3200"}, {26, "ПАЗ-672М"}, {27, "УралАЗ-512"},
        {28, "Икарус-260"}, {29, "ГАЗ-66"}
    };
    for (int i = 0; i < number_of_struct; i++)
    {
        Bus bus_vector;
        bus_vector.model = busMap[rand() % 30];
        bus_vector.lenght = round((3.0f + static_cast<double>(rand()) / (RAND_MAX / 12.0f)) * 100.0f) / 100.0f;
        bus_vector.height = round((2.0f + static_cast<double>(rand()) / (RAND_MAX / 6.0f)) * 100.0f) / 100.0f;
        bus_vector.max_passengers = 20 + rand() % 121;
        bus_vector.avg_passengers = bus_vector.max_passengers - ((rand() % bus_vector.max_passengers) / 2);
        result.push_back(bus_vector);
    }
    return result;
}

int write(string file_name, string mode)
{
    if (mode == "text")
    {
        int number_of_data;
        cout << "Введите количество записей: ";
        cin >> number_of_data;
        ofstream outFile(file_name, ios::app);
        if (outFile.is_open())
        {
            vector<Bus> bus_vector = generate_struct(number_of_data);
            for (int i = 0; i < number_of_data; i++)
            {
                string model = bus_vector[i].model;
                double lenght = bus_vector[i].lenght;
                double height = bus_vector[i].height;
                int max_passengers = bus_vector[i].max_passengers;
                int avg_passengers = bus_vector[i].avg_passengers;
                stringstream ss;
                ss << model << ";" << lenght << ";" << height << ";" << max_passengers << ";" << avg_passengers << ";";
                string data = ss.str();
                outFile << data << endl;
            }
            outFile.close();
        }
        else
        {
            return 0;
        }
    }
    if (mode == "binary")
    {
        int number_of_data;
        cout << "Введите количество записей: ";
        cin >> number_of_data;
        ofstream outFile(file_name, ios::app | ios::binary);
        if (outFile.is_open())
        {
            vector<Bus> bus_vector = generate_struct(number_of_data);
            for (int i = 0; i < number_of_data; i++)
            {
                string model = bus_vector[i].model;
                double lenght = bus_vector[i].lenght;
                double height = bus_vector[i].height;
                int max_passengers = bus_vector[i].max_passengers;
                int avg_passengers = bus_vector[i].avg_passengers;
                stringstream ss;
                ss << model << ";" << lenght << ";" << height << ";" << max_passengers << ";" << avg_passengers << ";";
                string data = ss.str();
                char buffer[101];
                strncpy_s(buffer, data.c_str(), 100);
                buffer[100] = '\0';
                outFile.write(buffer, sizeof(buffer));
            }
            outFile.close();
        }
        else
        {
            return 0;
        }
    }
}

vector<Bus> read(string file_name, string mode)
{
    vector<Bus> result;
    if (mode == "text")
    {
        string line;
        ifstream inFile(file_name);
        while (getline(inFile, line))
        {
            Bus currentBus;
            string currentLine;
            stringstream ss(line);
            int counter = 0;
            while (getline(ss, currentLine, ';'))
            {
                if (counter == 0) { currentBus.model = currentLine; }
                else if (counter == 1)
                {
                    stringstream ss2(currentLine);
                    double value;
                    ss2 >> value;
                    currentBus.lenght = value;
                }
                else if (counter == 2)
                {
                    stringstream ss2(currentLine);
                    double value;
                    ss2 >> value;
                    currentBus.height = value;
                }
                else if (counter == 3) { currentBus.max_passengers = stoi(currentLine); }
                else if (counter == 4) { currentBus.avg_passengers = stoi(currentLine); }
                counter++;
            }
            result.push_back(currentBus);
        }
    }
    if (mode == "binary")
    {
        ifstream inFile(file_name, ios::binary);
        if (inFile) {
            char buffer[101];
            while (inFile.read(buffer, sizeof(buffer))) {
                string str(buffer);
                Bus currentBus;
                string currentLine;
                stringstream ss(str);
                int counter = 0;
                while (getline(ss, currentLine, ';'))
                {
                    if (counter == 0) { currentBus.model = currentLine; }
                    else if (counter == 1)
                    {
                        stringstream ss2(currentLine);
                        double value;
                        ss2 >> value;
                        currentBus.lenght = value;
                    }
                    else if (counter == 2)
                    {
                        stringstream ss2(currentLine);
                        double value;
                        ss2 >> value;
                        currentBus.height = value;
                    }
                    else if (counter == 3) { currentBus.max_passengers = stoi(currentLine); }
                    else if (counter == 4) { currentBus.avg_passengers = stoi(currentLine); }
                    counter++;
                }
                result.push_back(currentBus);
            }
            inFile.close();
        }
        else {
            cout << "Ошибка при открытии файла для чтения." << endl;
        }
    }
    return result;
}

void clear(string file_name, string mode)
{
    if (mode == "text")
    {
        ofstream outFile(file_name, ios::trunc);
        if (outFile.is_open()) {
            outFile.close();
            cout << "Текстовый файл очищен." << endl;
        }
        else {
            cerr << "Ошибка при открытии файла для очистки." << endl;
        }
    }
    else if (mode == "binary")
    {
        ofstream outFile(file_name, ios::trunc);
        if (outFile.is_open()) {
            outFile.close();
            cout << "Файл очищен." << endl;
        }
        else {
            cerr << "Ошибка при открытии файла для очистки." << endl;
        }
    }
}
