/*
 * main.cpp
 * Main program for problem set 7 CPSC 427/527
 *
 *  Created on: Dec 10, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 */


#include <ctime>
#include <iostream>
#include "tools.hpp"
#include "Simulator.hpp"


// ----------------------------------------------------------------------------
// function declarations
// ----------------------------------------------------------------------------

void run( int argc, char* argv[] );
void readPara( int argc, char* argv[], int& numAgents, int& maxRounds, double&
		probNak, double& probFickle, double& probExtend, unsigned int& seedNum);
void printPara( int& numAgents, int& maxRounds, double& probNak, double& probFickle,
		double& probExtend );
void useMsg( char* argv[] );

int main( int argc, char* argv[] ) {
	banner();
	try {
		run( argc, argv );
	}
	catch (...) {
		cout << "Error: invalid argument(s). Please see usage message below: " << endl;
		useMsg( argv );
	}
	bye();
}

// ----------------------------------------------------------------------------
// function definitions
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// The run function uses readPara as a helper function to read in parameters
// through command line standard input. It then uses these parameters to first
// create a genesis block, initializes a genesis blockchain using the genesis block
// initializes a population of agents that are initialized with copies of the
// genesis blockchain, initializes a simulator using the population, and run
// maxRounds of simulation on the population. The relative statistics, simulation
// process, and simulation results are printed to stdout.

void run( int argc, char* argv[] ) {
	int numAgents, maxRounds;
	double probNak, probFickle, probExtend;
	unsigned int seedNum;

	Block* gen = Block::init_genesis();
	SPtr sp( gen );
	try {
		readPara( argc, argv, numAgents, maxRounds, probNak, probFickle, probExtend, seedNum );
	}
	catch (...) {
		throw "Error: invalid argument(s). ";
	}
	srandom( seedNum );
	Blockchain gen_chain( &sp );
	Population p ( numAgents, probFickle, probNak, probExtend, &gen_chain );
	Simulator s( &p, probExtend );

	cout << "Welcome to Consensus Simulator! " << endl;
	cout << "Using seed: " << seedNum << endl;
	printPara( numAgents, maxRounds, probNak, probFickle, probExtend );
	p.printStats();
	Inventory::print();
	cout << endl;
	s.run( maxRounds );
	s.print();
}

// ----------------------------------------------------------------------------
// Helper function used by run() function to read in and check parameters from
// command line input.

void readPara( int argc, char* argv[], int& numAgents, int& maxRounds, double&
		probNak, double& probFickle, double& probExtend, unsigned int& seedNum ) {
	string num_str, round_str, nak_str, f_str, ex_str, seed_str;
	bool good_format = true;

	if (argc != 6 && argc != 7) {
		throw "Invalid length of argument";
	}

	num_str = argv[1];
	round_str = argv[2];
	nak_str = argv[3];
	f_str = argv[4];
	ex_str = argv[5];

	try {
		numAgents = stoi( num_str );
		maxRounds = stoi( round_str );
		probNak = stod( nak_str );
		probFickle = stod( f_str );
		probExtend = stod( ex_str );

		if (numAgents < 0) {
			good_format = false;
			cout << "Error: total number of agents cannot be negative. " << endl;
		}
		if (maxRounds < 0) {
			good_format = false;
			cout << "Error: max number of rounds cannot be negative. " << endl;
		}
		if (probNak < 0 || probNak > 1) {
			good_format = false;
			cout << "Error: probability of selecting a Nakamoto agent should be "
					"between 0 and 1. " << endl;
		}
		if (probFickle < 0 || probFickle > 1) {
			good_format = false;
			cout << "Error: probability of selecting a Fickle agent should be "
					"between 0 and 1. " << endl;
		}
		if (probFickle + probNak > 1) {
			good_format = false;
			cout << "Error: probFickle + probNak is greater than 1. " << endl;
		}
		if (probExtend < 0 || probExtend > 1) {
			good_format = false;
			cout << "Error: probability of extending operation should be between "
					"0 and 1. " << endl;
		}
	}
	catch (std::invalid_argument& e) {
		cout << "Error: invalid argument: " <<endl;
		good_format = false;
	}

	if (argc == 7) {
		seed_str = argv[6];
		try {
			int temp = stoi( seed_str );
			if (temp < 0) {
				good_format = false;
				cout << "Error: seed is NOT an unsigned integer. " << endl;
			}
			else {
				seedNum = temp;
			}

		}
		catch (std::invalid_argument& e) {
			cout << "Error: invalid argument when converting seedNum: " << endl;
			good_format = false;
		}
	}
	else {
		seedNum = time( 0 );
	}

	if (!good_format) {
		throw "Invalid argument after conversion. ";
	}
}

// ----------------------------------------------------------------------------
// Helper function used by run() to print relative parameters to stdout.

void printPara( int& numAgents, int& maxRounds, double& probNak, double& probFickle,
		double& probExtend ) {
	int width_1 = 13;
	int width_2 = 7;
	cout << right << setw( width_1 ) << "numAgents:" << right << setw( width_2 ) << numAgents << endl;
	cout << right << setw( width_1 ) << "maxRounds:" << right << setw( width_2 ) << maxRounds << endl;
	cout << right << setw( width_1 ) << "probNak:" << right << setw( width_2 ) << fixed <<
			setprecision(2) << probNak << endl;
	cout << right << setw( width_1 ) << "probFickle:" << right << setw( width_2 ) << fixed <<
			setprecision(2) << probFickle << endl;
	cout << right << setw( width_1 ) << "probExtend:" << right << setw( width_2 ) << fixed <<
			setprecision(2) << probExtend << endl;
	cout << endl;
}

// ----------------------------------------------------------------------------
// Helper function used by run() to print information on how to use the consensus
// simulator on blockchain.

void useMsg( char* argv[] ) {
	cout << "Usage: ./" << argv[0] << " numAgents maxRounds probNak probFickle"
			" probExtend [seed]" << endl;
	cout << "numAgents: total number of agents. " << endl;
	cout << "maxRounds: total number of simulation rounds to perform. " << endl;
	cout << "probNak: probability of selecting a Nakamoto agent when building "
			"the population. " << endl;
	cout << "probFickle: probability of selecting a Fickle agent when building "
			"the population. " << endl;
	cout << "probExtend: probability of extend() operation for the simulator. "
			<< endl;
	cout << "[seed] optional seed for the random number generator. " << endl;
}
