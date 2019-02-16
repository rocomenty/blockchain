/* ----------------------------------------------------------------------------
 * Simulator class header                                         Simulator.hpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Simulator class that performs simulation of different
 * types of agents attempting to reach consensus.
 */

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <iostream>
#include "Population.hpp"

class Simulator {
private:
	Population* pop;
	int rounds;
	const double probExtend;
	int uRandom( int n );
	inline double dRandom() { return random() / (RAND_MAX + 1.0); }

public:
	Simulator( Population* p, double pE ) : pop(p), rounds(0), probExtend(pE) {};
	~Simulator() = default;
	void run( int maxRounds );
	inline int numRounds() const { return rounds; }
	void print() const;
};

#endif /* SIMULATOR_HPP */
