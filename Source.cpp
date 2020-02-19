#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "Neuron.h"
#include "Training.h"
#include "Functions.h"

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
	//cout << summ(5, 6);
}

int main() {
	freopen("result.out", "w", stdout);

	/*Test();*/

	Umink();
	return 0;
}
int Answer(vector <Neuron> & OutLayer) {
	int Answer;
	double MaxValue = -1;

	for (int i = 0; i < OutLayer.size(); ++i) {
		if (OutLayer[i].value > MaxValue) {
			MaxValue = OutLayer[i].value;
			Answer = i;
		}
	}

	return Answer;
}