#ifndef MnistReader_H
#define MnistReader_H

#include <iostream>
#include <fstream>

using namespace std;

ifstream picture0("data0", ios_base::binary);
ifstream picture1("data1", ios_base::binary);
ifstream picture2("data2", ios_base::binary);
ifstream picture3("data3", ios_base::binary);
ifstream picture4("data4", ios_base::binary);
ifstream picture5("data5", ios_base::binary);
ifstream picture6("data6", ios_base::binary);
ifstream picture7("data7", ios_base::binary);
ifstream picture8("data8", ios_base::binary);
ifstream picture9("data9", ios_base::binary);

double MnistReader(int & DesiredNumber);

void MnistClose();

#endif