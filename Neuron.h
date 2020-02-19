#ifndef NEURON_H
#define NEURON_H

#include <fstream>
#include <iostream>
#include <vector>
#include "MnistReader.h"

using namespace std;

double Sigmoid(double & x) {
	return 1 / (1 + exp(-x));
}

class Neuron {
public:

	double value;
	vector < double > weights;

	Neuron() {
		for (int i = 0; i < 10; ++i)
			weights.emplace_back((rand() % 100 - 50) / 100.);
	}

	void NewNumber(int & DesiredNumber) {
		value = MnistReader(DesiredNumber);
	}

	void Multiplication(vector <Neuron> & InLayer, int & DesiredNeuron) {
		value = 0.;

		for (int i = 0; i < InLayer.size(); ++i)
			value += InLayer[i].value * InLayer[i].weights[DesiredNeuron];

		value = Sigmoid(value);
	}
};
#endif
