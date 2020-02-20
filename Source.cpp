#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

#include "Neuron.h"
#include "MnistReader.h"

using namespace std;

void Umink() {
	vector <Neuron> InLayer(784);
	int DesiredNumber;
	double TempValue;

	for (int j = 0; j < 10000; ++j) {
		DesiredNumber = j % 10;

		for (int i = 0; i < InLayer.size(); ++i) {
			TempValue = MnistReader(DesiredNumber);
			InLayer[i].NewNumber(TempValue);
		}

	}
	cout << DesiredNumber;
}

void Test() {

}

int main() {
	freopen("result.out", "w", stdout);

	/*Test();*/

	Umink();
	return 0;
}
