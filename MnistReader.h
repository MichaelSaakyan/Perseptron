#ifndef MNISTREADER_H
#define MNISTREADER_H

#include <iostream>
#include <fstream>

using namespace std;

static ifstream picture0("data0", ios_base::binary);
static ifstream picture1("data1", ios_base::binary);
static ifstream picture2("data2", ios_base::binary);
static ifstream picture3("data3", ios_base::binary);
static ifstream picture4("data4", ios_base::binary);
static ifstream picture5("data5", ios_base::binary);
static ifstream picture6("data6", ios_base::binary);
static ifstream picture7("data7", ios_base::binary);
static ifstream picture8("data8", ios_base::binary);
static ifstream picture9("data9", ios_base::binary);

double MnistReader(int & DesiredNumber);

void MnistClose();

#endif // !MNISTREADER_H