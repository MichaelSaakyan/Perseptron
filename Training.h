#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
#include <vector>
#include "Neuron.h"
using namespace std;

double error, weightsDelta, learningRate = 0.1;

void Calculations(vector <Neuron> & InLayer, vector <Neuron> & OutLayer, int & RightAnswer);
#endif // !TRAINING.H
