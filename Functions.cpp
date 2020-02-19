#include "Functions.h"

using namespace std;

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
