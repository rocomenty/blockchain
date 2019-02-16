/* ----------------------------------------------------------------------------
 * Simulator class implementation                                 Simulator.cpp
 *
 *  Created on: Oct 24, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Function definitions for the Simulator class that performs simulation of
 * agents attempting to reach consensus using specified algorithms under the
 * random-pair communication model.
 */

#include "Simulator.hpp"

// ----------------------------------------------------------------------------
// This function returns a uniformly-distributed random integer from [0 ... n-1]

int Simulator::uRandom( int n ) {
	long int usefulMax = RAND_MAX - ((RAND_MAX-n) + 1)%n;
	long int r;
	do { r = random(); }
	while (r > usefulMax);
	return r % n;
}

// ----------------------------------------------------------------------------
// This function runs simulation on the population for maxRounds number of rounds
// each rounds deciding to extend a blockchain or to simulate a communication
// step between two blockchains. Note: if the number of agents is 0, simulation is
// simply skipped. If the number of agents is 1, communication step is skipped.

void Simulator::run( int maxRounds ) {
	double prob;
	int sender_i, receiver_i, extend_i;
	cout << "Starting simulation with probExtend = " << probExtend << endl;
	if (pop->size() == 0) {
		rounds = maxRounds;
		maxRounds = 0;
		cout << "  Simulation skipped due to 0 agents. " << endl;
	}
	while (maxRounds > 0) {
		prob = dRandom();

		if (prob < probExtend) {
			extend_i = uRandom( pop->size() );
			pop->extend( extend_i );
		}
		else if ( pop->size() > 1 ) {
			sender_i = uRandom( pop->size() );
			receiver_i = uRandom( pop->size() - 1 );
			if (receiver_i >= sender_i) {
				receiver_i ++;
			}

			pop->sendMessage( sender_i, receiver_i );
		}
		else {
			cout << "  sendMessage cannot be done due to single agent. " << endl;
		}
		++rounds;
		--maxRounds;
	}
}

// ----------------------------------------------------------------------------
// This function prints the population (delegated to Population class)

void Simulator::print() const {
	cout << "Current blockchain choices after " << rounds << " rounds: " << endl;
	pop->print();
}
