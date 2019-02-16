/* ----------------------------------------------------------------------------
 * Agent class header                                                 Agent.hpp
 *
 *  Created on: Oct 24, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Header file for the Agent class that models after a single agent in the
 * consensus problem.
 */

#ifndef AGENT_HPP
#define AGENT_HPP

#include <iostream>
#include "Blockchain.hpp"

class Agent {

public:
	virtual ~Agent() {}

	virtual void update( Blockchain m ) = 0;
	virtual Blockchain choice() = 0;
	virtual void extend() = 0;
};



#endif /* AGENT_HPP */
