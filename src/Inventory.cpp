/* ----------------------------------------------------------------------------
 * Inventory class implementation                                 Inventory.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Implementation file for the Inventory class that keeps a static copy of map
 * used to keep track of active blockchains and corresponding number of agents
 * that have the blockchain as their current choice. The static map is initialized
 * here.
 */

#include "Inventory.hpp"

std::map<Blockchain, int> Inventory::inv_map;
