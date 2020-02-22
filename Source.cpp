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

	for (int k = 0; k < 10; ++k) {
		for (int j = 0; j < 10000; ++j) {
			DesiredNumber = j % 10;

			for (int i = 0; i < InLayer.size(); ++i) {
				TempValue = MnistReader(DesiredNumber);
				InLayer[i].NewNumber(TempValue);
			}

			OutLayer OutLayer(InLayer);

			if (DesiredNumber != OutLayer.Answer())
				OutLayer.Calculations(DesiredNumber, InLayer);
		}

		MnistClose();
	}
	int t = 0;

	for (int j = 0; j < 10000; ++j) {
		DesiredNumber = j % 10;

		for (int i = 0; i < InLayer.size(); ++i) {
			TempValue = MnistReader(DesiredNumber);
			InLayer[i].NewNumber(TempValue);
		}

		OutLayer OutLayer(InLayer);

		cout << OutLayer.Answer() << ' ';

		if (DesiredNumber != OutLayer.Answer())
			t++;
	}
	cout << t;
}

void Test() {

}

int main() {
	freopen("result.out", "w", stdout);

	/*Test();*/

	Umink();
	return 0;
}
