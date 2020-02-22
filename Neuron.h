#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

using namespace std;

double Sigmoid(double & x);

class Neuron {
public:
	double Value;
	vector <double> Weights;
	double LearningRate;

	Neuron();
	
	void NewNumber(double & TempValue);

	double Multiplication(int & Number);

	void Training(double & WeightsDelta, int & Number);
};

#endif // !NEURON_H
