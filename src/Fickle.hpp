/* ----------------------------------------------------------------------------
 * Fickle class header                                               Fickle.hpp
 *
 *  Created on: Nov 2, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Fickle class that models after an agent that behaves
 * according to the Fickle algorithm to reach consensus.
 */

#ifndef FICKLE_HPP
#define FICKLE_HPP
#include "AgentBase.hpp"

class Fickle : public AgentBase {

public:
	Fickle( Blockchain* ch ) : AgentBase( ch ) {};
	~Fickle() = default;

	inline void update( Blockchain m ) override { c = m; }
};



#endif /* FICKLE_HPP */
