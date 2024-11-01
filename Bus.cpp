#include "Bus.h"

void Bus::writeBinary(ofstream& outFile) const
{
    outFile.write(model.c_str(), model.size() + 1);
    outFile.write(reinterpret_cast<const char*>(&lenght), sizeof(lenght));
    outFile.write(reinterpret_cast<const char*>(&height), sizeof(height));
    outFile.write(reinterpret_cast<const char*>(&max_passengers), sizeof(max_passengers));
    outFile.write(reinterpret_cast<const char*>(&avg_passengers), sizeof(avg_passengers));
}