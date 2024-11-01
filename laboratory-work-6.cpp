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
		{0, "ËèÀÇ-677"}, {1, "ÏÀÇ-3205"}, {2, "ÊÀÂÇ-685"}, {3, "Èêàğóñ-250"},
		{4, "ĞÀÔ-2203"}, {5, "ÃÀÇ-03-30"}, {6, "ÇèÑ-155"}, {7, "ÇèË-158"},
		{8, "ÊÀâÇ-3270"}, {9, "ÌÀÇ-103"}, {10, "ÍåôÀÇ-5299"}, {11, "Èêàğóñ-280"},
		{12, "ÏÀÇ-672"}, {13, "ËÀÇ-695"}, {14, "ÌÀĞÇ-5266"}, {15, "ÇèÑ-154"},
		{16, "ËèÀÇ-5256"}, {17, "ËÀÇ-699Ğ"}, {18, "ÏÀÇ-4234"}, {19, "ËÀÇ-4202"},
		{20, "ÏÀÇ-652"}, {21, "ÇèË-127"}, {22, "ËèÀÇ-5292"}, {23, "ÃÀÇåëü Next"},
		{24, "ŞÌÇ-Ò1"}, {25, "Òàäæèêèñòàí-3200"}, {26, "ÏÀÇ-672Ì"}, {27, "ÓğàëÀÇ-512"},
		{28, "Èêàğóñ-260"}, {29, "ÃÀÇ-66"}
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