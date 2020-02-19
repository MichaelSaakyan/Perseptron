#include "Training.h"
using namespace std;

void Calculations(vector <Neuron> & InLayer, vector <Neuron> & OutLayer, int & RightAnswer) {
	for (int i = 0; i < OutLayer.size(); ++i) {
		if (i == RightAnswer) {
			error = OutLayer[i].value - 1;
		}
		else {
			error = OutLayer[i].value;
		}

		weightsDelta = error * OutLayer[i].value * (1 - OutLayer[i].value);

		for (int j = 0; j < InLayer.size(); ++j)
			InLayer[j].weights[i] = InLayer[j].weights[i] - InLayer[j].value * weightsDelta * learningRate;

	}
}