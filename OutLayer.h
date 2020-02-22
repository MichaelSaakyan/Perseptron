#ifndef OUTLAYER_H
#define OUTLAYER_H

#include <iostream>
#include <vector>

#include "Neuron.h"

using namespace std;

class OutLayer {
public:
	vector <double> Values;

	OutLayer(vector <Neuron> & InLayer);
	
	int Answer();

	void Calculations(int & DesiredNumber, vector <Neuron> & InLayer);
};

#endif // !OUTLAYER_H