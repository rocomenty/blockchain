/* ----------------------------------------------------------------------------
 * Crowd class header                                                 Crowd.hpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Crowd class that models after an agent that behaves
 * according to the Follow-the-Crowd algorithm to reach consensus.
 */

#ifndef CROWD_HPP
#define CROWD_HPP
#include "AgentBase.hpp"

class Crowd : public AgentBase {
private:
	Blockchain s;

public:
	Crowd( Blockchain* ch ) : AgentBase( ch ), s(*ch) {};
	~Crowd() = default;

	inline void update( Blockchain m ) override { m == s ? c = m : s = m; }
};





#endif /* CROWD_HPP */
