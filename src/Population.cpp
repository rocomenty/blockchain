/* ----------------------------------------------------------------------------
 * Population class implementation                               Population.cpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Function definitions for the Population class that maintain an aggregated
 * array of Agents in the consensus problem.
 */

#include "Population.hpp"

// ----------------------------------------------------------------------------
// The constructor first initialize an array of Agent pointers. Then it uses
// the dRandom function to the Agent's type, and initializes the Agent using
// the genesis blockchain.

Population::Population( int numAgent, double probFickle, double probNak,
		double probExtend, Blockchain* bc_genesis ) : totalNum(numAgent),
		probF(probFickle), probN(probNak), probEx(probExtend), numNak(0),
		numFickle(0), agents(new Agent*[numAgent]) {
	double prob;
	for (int k = 0; k < numAgent; k++) {
		prob = dRandom();

		if (prob < probN) {
			agents[k] = new Nakamoto( bc_genesis );
			++numNak;
		}
		else if (prob >= probN && prob < (probF + probN)) {
			agents[k] = new Fickle( bc_genesis );
			++numFickle;
		}
		else {
			agents[k] = new Crowd( bc_genesis );
		}
		Inventory::add( *bc_genesis );
	}
}

// ----------------------------------------------------------------------------
// The destructor needs to first delete the individual agent objects created
// using new in the constructor. It then deletes the dynamically allocated array
// of Agent pointers.

Population::~Population() {
	for (int m = 0; m < totalNum; m++) delete agents[m];
	delete [] agents;
}

// ----------------------------------------------------------------------------
// This function simulates a single communication step from sender to receiver.

void Population::sendMessage( int sender, int receiver ) {
	cout << "  sendMessage(" << sender << ", " << receiver << ")" << endl;
	Blockchain old_choice = agents[receiver]->choice();
	agents[receiver]->update( agents[sender]->choice() );
	if (agents[receiver]->choice() != old_choice) {
		Inventory::add( agents[receiver]->choice() );
		Inventory::sub( old_choice );
		Inventory::print();
	}
}

// ----------------------------------------------------------------------------
// This function prints relative statistical info of the population to stdout.

void Population::printStats() {
	int width_1 = 13;
	int width_2 = 7;
	cout << "Population statistics:" << endl;
	cout << right << setw(width_1) << "numNak: " << right << setw(width_2) <<
			numNak << endl;
	cout << right << setw(width_1) << "numFickle: " << right << setw(width_2) <<
			numFickle << endl;
	cout << right << setw(width_1) << "numCrowd: " << right << setw(width_2) <<
			(totalNum - numNak - numFickle) << endl;
	cout << right << setw(width_1) << "probExtend: " << right << setw(width_2) <<
			fixed << setprecision(2) << probEx << endl;
	cout << endl;
}

// ----------------------------------------------------------------------------
// This function prints each Agent's choice line by line (delegated to the Agent
// class).

void Population::print() {
	for (int m = 0; m < totalNum; ++m) {
		cout << "Agent " << m << " choice: ";
		agents[m]->choice().print(cout);
		cout << endl;
	}
}
