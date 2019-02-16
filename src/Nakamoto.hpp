/* ----------------------------------------------------------------------------
 * Nakamoto class header                                           Nakamoto.hpp
 *
 *  Created on: Dec 9, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Header file for the Nakamoto class that models after an agent that behaves
 * according to the Nakamoto algorithm to reach consensus on blockchain.
 */

#ifndef NAKAMOTO_HPP_
#define NAKAMOTO_HPP_

#include "AgentBase.hpp"

class Nakamoto : public AgentBase {

public:
	Nakamoto( Blockchain* ch ) : AgentBase( ch ) {}

	inline void update( Blockchain m ) override { if (m.length() > c.length()) c = m; }
};



#endif /* NAKAMOTO_HPP_ */
