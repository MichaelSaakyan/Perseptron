#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <math.h>

#include "Neuron.h"
#include "MnistReader.h"
#include "OutLayer.h"

using namespace std;

void Umink() {
	vector <Neuron> InLayer(784);
	int DesiredNumber;
	double TempValue;

	for (int j = 0; j < 100; ++j) {
		DesiredNumber = j % 10;

		for (int i = 0; i < InLayer.size(); ++i) {
			TempValue = MnistReader(DesiredNumber);
			InLayer[i].NewNumber(TempValue);
		}

		OutLayer OutLayer(InLayer);

		if (DesiredNumber != OutLayer.Answer())
			OutLayer.Calculations(DesiredNumber, InLayer);
	}

	int Temp = 0;

	for (int j = 0; j < 1000; ++j) {
		DesiredNumber = j % 10;

		for (int i = 0; i < InLayer.size(); ++i) {
			TempValue = MnistReader(DesiredNumber);
			InLayer[i].NewNumber(TempValue);
		}

		OutLayer OutLayer(InLayer);

		if (DesiredNumber != OutLayer.Answer())
			Temp++;
	}

	cout << (1000 - Temp) / 10;
	MnistClose();
}

void Test() {

}

int main() {
	freopen("result.out", "w", stdout);

	/*Test();*/

	Umink();
	return 0;
}
