#include "Neuron.h"

using namespace std;

Neuron::Neuron() {

	for (int i = 0; i < 10; i++) 
		weights.emplace_back((rand() % 100 - 50) / 100.);
}

void 
Neuron::NewNumber(double & TempValue) {
	value = TempValue;
}

double Sigmoid(double & x) {
	return 1 / (1 + exp(-x));
}
