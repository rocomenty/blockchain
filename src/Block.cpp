/* ----------------------------------------------------------------------------
 * Block class implementation                                         Block.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Function definitions for the Block class that models after a single block in
 * a blockchain.
 */


#include "Block.hpp"
// ----------------------------------------------------------------------------
// static boolean to ensure only one genesis block is initialized

bool Block::genesis_initialized = false;

// ----------------------------------------------------------------------------
// print function that returns a string. This function is used as a helper
// function for printChain where all blocks in a blockchain are printed.

std::string Block::print() const {
	return "[" + std::to_string( level ) + "," + std::to_string( serialNo ) + "]";
}

// ----------------------------------------------------------------------------
// a normal print function that print the level and serialNo of a block to an
// ostream reference

std::ostream& Block::print( std::ostream& out ) const {
	out << "[" << level << "," << serialNo << "]";
	return out;
}

// ----------------------------------------------------------------------------
// print function that prints all blocks in the blockchain starting from the
// current block

std::ostream& Block::printChain( std:: ostream& out ) const {
	std::vector<string> v;
	string s = print();
	v.push_back( s );
	for (Block* b = sp.target_ptr(); b != nullptr; b = b->sp.target_ptr()) {
		s = b->print();
		v.push_back( s );
	}

	for (auto k = v.rbegin(); k != v.rend(); ++k) {
		out << *k;
	}
	return out;
}
