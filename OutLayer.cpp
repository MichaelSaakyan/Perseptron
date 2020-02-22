#include "OutLayer.h"
#include "Neuron.h"

OutLayer::OutLayer(vector <Neuron> & InLayer) {
	Values.resize(10);

	for (int i = 0; i < Values.size(); ++i) {
		for (int j = 0; j < InLayer.size(); ++j) 
			Values[i] += InLayer[j].Multiplication(i);
		
		Values[i] = Sigmoid(Values[i]);
	}
}

int
OutLayer::Answer() {
	int Answer;
	double Maximum = -1.;

	for (int i = 0; i < Values.size(); ++i) {
		if (Values[i] > Maximum) {
			Answer = i;
			Maximum = Values[i];
		}
	}

	return Answer;
}

void
OutLayer::Calculations(int & DesiredNumber, vector <Neuron> & InLayer) {
	double Error, WeightsDelta;

	for (int i = 0; i < Values.size(); ++i) {
		if (i == DesiredNumber) {
			Error = Values[i] - 1;
		}
		else {
			Error = Values[i];
		}

		WeightsDelta = Error * Values[i] * (1 - Values[i]);

		for (int j = 0; j < InLayer.size(); ++j)
			InLayer[j].Training(WeightsDelta, i);
	}
}