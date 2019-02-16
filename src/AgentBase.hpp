/* ----------------------------------------------------------------------------
 * AgentBase class header                                         AgentBase.hpp
 *
 *  Created on: Dec 9, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Header file for the AgentBase class that models after a single agent in the
 * consensus problem. This class serves as a common base class for other three
 * class that implements three different kinds of agents: Nakamoto, Crowd, and
 * Fickle.
 */

#ifndef AGENTBASE_HPP_
#define AGENTBASE_HPP_

#include "Agent.hpp"
#include "Blockchain.hpp"
#include "Inventory.hpp"

class AgentBase : public Agent {
protected:
	Blockchain c;
	AgentBase( Blockchain* ch ) : c(*ch) {}
public:
	inline Blockchain choice() override { return Blockchain( c ); }
	inline void extend() override {
		Inventory::sub( c );
		c = c.extend();
		Inventory::add( c );
		cout << "  New blockchain: ";
		c.print( cout );
		cout << endl;
		Inventory::print();
	}
};



#endif /* AGENTBASE_HPP_ */
