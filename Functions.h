#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include "Bus.h"

using namespace std;

vector<Bus> generate_struct(int number_of_struct);
void write(string file_name, string mode);
vector<Bus> read(string file_name, string mode);
void clear(string file_name, string mode);

#endif