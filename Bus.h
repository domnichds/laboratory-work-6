#ifndef BUS_H
#define BUS_H

#include <string>
#include <fstream>

using namespace std;

struct Bus
{
	string model;
	double lenght;
	double height;
	int max_passengers;
	int avg_passengers;

	void writeBinary(ofstream& outFile) const;
};

#endif // BUS_H
