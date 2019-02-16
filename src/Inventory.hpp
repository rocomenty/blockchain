/* ----------------------------------------------------------------------------
 * Inventory class header                                         Inventory.hpp
 *
 *  Created on: Dec 11, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Header file for the Inventory class that keeps a static copy of map used to
 * keep track of active blockchains and corresponding number of agents that have
 * the blockchain as their current choice.
 */

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <map>
#include "Blockchain.hpp"

class Inventory {
private:
	static std::map<Blockchain, int> inv_map;

public:
	inline static void add( Blockchain b ) {
		if (inv_map.find( b ) != inv_map.end()) {
			inv_map[b] += 1;
		}
		else {
			inv_map[Blockchain( b )] = 1;
		}
	}
	inline static void sub( Blockchain b ) {
		if (--inv_map[b] == 0) {
			inv_map.erase( b );
		}
	}

	inline static void print() {
		cout << "Inventory: " << inv_map.size() << " active blockchain(s):" << endl;
		for (auto m = inv_map.crbegin(); m != inv_map.crend(); ++m) {
			cout << "  " << m->second << " copies of " << m->first << endl;
		}
	}
};



#endif /* INVENTORY_HPP_ */
