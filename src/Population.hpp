/* ----------------------------------------------------------------------------
 * Population class header                                       Population.hpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Population class that maintain an aggregated array of
 * Agents in the consensus problem.
 */

#ifndef POPULATION_HPP
#define POPULATION_HPP
#include <random>
#include <iostream>
#include <iomanip>
#include "AgentBase.hpp"
#include "Fickle.hpp"
#include "Crowd.hpp"
#include "Nakamoto.hpp"
#include "Inventory.hpp"

class Population {
private:
	const int totalNum;
	const double probF;
	const double probN;
	const double probEx;
	int numNak;
	int numFickle;
	Agent** agents;

	inline double dRandom() { return random() / (RAND_MAX + 1.0); }

public:
	Population( int numAgent, double probFickle, double probNak, double probExtend,
			Blockchain* bc_genesis );
	~Population();
	Population( const Population& other );

	inline int size() const { return totalNum; }
	inline void extend( int receiver ) {
		cout << "  extend(" << receiver << ")" << endl;
		agents[receiver]->extend();
	}
	void sendMessage( int sender, int receiver );
	void printStats();
	void print();
};

#endif /* POPULATION_HPP */
