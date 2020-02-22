#include "Neuron.h"

using namespace std;

double Sigmoid(double & x) {
	return 1. / (1. + exp(-x));
}

Neuron::Neuron() {
	LearningRate = 0.3;

	for (int i = 0; i < 10; i++) 
		Weights.emplace_back((rand() % 100 - 50) / 100.);
}

void 
Neuron::NewNumber(double & TempValue) {
	Value = TempValue;
}

double
Neuron::Multiplication(int & Number) {
	return Value * Weights[Number];
}

void
Neuron::Training(double & WeightsDelta, int & Number) {
	Weights[Number] -= Value * WeightsDelta * LearningRate;
}