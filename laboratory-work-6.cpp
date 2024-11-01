#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct Bus
{
	string model;
	double lenght;
	double height;
	int max_passengers;
	int avg_passengers;
};



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
		bus_vector.lenght = round((3.0f + static_cast<float>(rand()) / (RAND_MAX / 12.0f)) * 100.0f) / 100.0f;
		bus_vector.height = round((2.0f + static_cast<float>(rand()) / (RAND_MAX / 6.0f)) * 100.0f) / 100.0f;
		bus_vector.max_passengers = 20 + rand() % 121;
		bus_vector.avg_passengers = bus_vector.max_passengers - ((rand() % bus_vector.max_passengers) / 2);
		result.push_back(bus_vector);
	}
	return result;

}
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	string mode = argv[1];
	string file_type = argv[2];
	string file_name = argv[3];
	return 0;
}