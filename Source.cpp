#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "Neuron.h"
#include "Functions.h"
#include "Training.h"

using namespace std;

void Umink() {
	vector <Neuron> InLayer(784);
	vector <Neuron> OutLayer(10);

	

	for (int i = 0; i < 10000; ++i) {
		
		int DesiredNumber = i % 10;

		for (int j = 0; j < InLayer.size(); ++j)
			InLayer[j].NewNumber(DesiredNumber);

		for (int j = 0; j < 10; ++j)
			OutLayer[j].Multiplication(InLayer, j);
		
		if (DesiredNumber != Answer(OutLayer)) 
			Calculations(InLayer, OutLayer, DesiredNumber);
			
	}
	
	MnistClose();
	int NumbOfCorrectAns = 0;

	for (int i = 0; i < 10000; ++i) {

		int DesiredNumber = i % 10;

		for (int j = 0; j < InLayer.size(); ++j)
			InLayer[j].NewNumber(DesiredNumber);

		for (int j = 0; j < 10; ++j)
			OutLayer[j].Multiplication(InLayer, j);

		if (DesiredNumber == Answer(OutLayer))
			NumbOfCorrectAns++;

	}
	cout << NumbOfCorrectAns / 100;
}

void Test() {
	ifstream picture("data1", ios_base::binary);
	for (int i = 0; i < 784; ++i) {
		unsigned char temp = 0;
		picture.read((char*)&temp, sizeof(temp));
		if ((int)temp != 0) cout << "0";
		else cout << ' ';
		if (i % 28 == 0) cout << "\n";
	}
	picture.close();
}

int main() {
	freopen("result.out", "w", stdout);

	//Test();

	Umink();
	return 0;
}