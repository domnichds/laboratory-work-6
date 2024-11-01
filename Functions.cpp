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
        {0, "����-677"}, {1, "���-3205"}, {2, "����-685"}, {3, "������-250"},
        {4, "���-2203"}, {5, "���-03-30"}, {6, "���-155"}, {7, "���-158"},
        {8, "����-3270"}, {9, "���-103"}, {10, "�����-5299"}, {11, "������-280"},
        {12, "���-672"}, {13, "���-695"}, {14, "����-5266"}, {15, "���-154"},
        {16, "����-5256"}, {17, "���-699�"}, {18, "���-4234"}, {19, "���-4202"},
        {20, "���-652"}, {21, "���-127"}, {22, "����-5292"}, {23, "������ Next"},
        {24, "���-�1"}, {25, "�����������-3200"}, {26, "���-672�"}, {27, "������-512"},
        {28, "������-260"}, {29, "���-66"}
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

void write(string file_name, string mode)
{
    if (mode == "text")
    {
        int number_of_data;
        cout << "������� ���������� �������: ";
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
            cout << "������� �������� " << number_of_data << " �����" << endl;
        }
        else
        {
            cout << "��������� ������ ������!" << endl;
        }
    }
    if (mode == "binary")
    {
        int number_of_data;
        cout << "������� ���������� �������: ";
        cin >> number_of_data;
        ofstream outFile(file_name, ios::app | ios::binary);
        if (outFile.is_open())
        {
            vector<Bus> bus_vector = generate_struct(number_of_data);
            for (int i = 0; i < number_of_data; i++)
            {
                size_t model_length = bus_vector[i].model.size();
                outFile.write(reinterpret_cast<const char*>(&model_length), sizeof(model_length));
                outFile.write(bus_vector[i].model.c_str(), model_length);
                outFile.write(reinterpret_cast<const char*>(&bus_vector[i].lenght), sizeof(bus_vector[i].lenght));
                outFile.write(reinterpret_cast<const char*>(&bus_vector[i].height), sizeof(bus_vector[i].height));
                outFile.write(reinterpret_cast<const char*>(&bus_vector[i].max_passengers), sizeof(bus_vector[i].max_passengers));
                outFile.write(reinterpret_cast<const char*>(&bus_vector[i].avg_passengers), sizeof(bus_vector[i].avg_passengers));
            }
            outFile.close();
            cout << "������� �������� " << number_of_data << " �����" << endl;
        }
        else
        {
            cout << "��������� ������ ������!" << endl;
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
        if (inFile)
        {
            while (getline(inFile, line))
            {
                Bus currentBus;
                string currentLine;
                stringstream ss(line);
                int counter = 0;
                while (getline(ss, currentLine, ';'))
                {
                    try
                    {
                        if (counter == 0) { currentBus.model = currentLine; }
                        else if (counter == 1)
                        {
                            stringstream ss2(currentLine);
                            double value;
                            ss2 >> value;
                            if (ss2.fail()) { throw invalid_argument("������������ �������� � double"); }
                            currentBus.lenght = value;
                        }
                        else if (counter == 2)
                        {
                            stringstream ss2(currentLine);
                            double value;
                            ss2 >> value;
                            if (ss2.fail()) { throw invalid_argument("������������ �������� � double"); }
                            currentBus.height = value;
                        }
                        else if (counter == 3) { currentBus.max_passengers = stoi(currentLine); }
                        else if (counter == 4) { currentBus.avg_passengers = stoi(currentLine); }
                    }
                    catch (...)
                    {
                        cout << "������������ ������ � �����!" << endl;
                        exit(1);
                    }
                    counter++;
                }
                result.push_back(currentBus);
            }
            inFile.close();
        }
        else
        {
            cout << "������ ������ �����" << endl;
            exit(1);
        }
    }
    if (mode == "binary")
    {
        ifstream inFile(file_name, ios::binary);
        if (inFile)
        {
            while (true)
            {
                Bus currentBus;

                size_t model_length;
                inFile.read(reinterpret_cast<char*>(&model_length), sizeof(model_length));
                if (inFile.eof()) break;
                char* model_buffer = new char[model_length + 1];
                inFile.read(model_buffer, model_length);
                model_buffer[model_length] = '\0';
                currentBus.model = string(model_buffer);
                delete[] model_buffer;
                inFile.read(reinterpret_cast<char*>(&currentBus.lenght), sizeof(currentBus.lenght));
                inFile.read(reinterpret_cast<char*>(&currentBus.height), sizeof(currentBus.height));
                inFile.read(reinterpret_cast<char*>(&currentBus.max_passengers), sizeof(currentBus.max_passengers));
                inFile.read(reinterpret_cast<char*>(&currentBus.avg_passengers), sizeof(currentBus.avg_passengers));
                result.push_back(currentBus);
            }
            inFile.close();
        }
        else
        {
            cout << "������ ������ �����" << endl;
            exit(1);
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
            cout << "��������� ���� ������." << endl;
        }
        else {
            cerr << "������ ��� �������� ����� ��� �������." << endl;
        }
    }
    else if (mode == "binary")
    {
        ofstream outFile(file_name, ios::trunc);
        if (outFile.is_open()) {
            outFile.close();
            cout << "���� ������." << endl;
        }
        else {
            cerr << "������ ��� �������� ����� ��� �������." << endl;
        }
    }
}
