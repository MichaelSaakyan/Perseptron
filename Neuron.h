#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>

using namespace std;

double Sigmoid(double & x);

class Neuron {
public:
	double value;
	vector <double> weights;

	Neuron();
	
	void NewNumber(double & TempValue);


};

#endif // !NEURON_H
