/* ----------------------------------------------------------------------------
 * Blockchain class implementation                               Blockchain.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Function definitions for the Blockchain class that models after a single
 * blockchain.
 */

#include "Blockchain.hpp"

// ----------------------------------------------------------------------------
// dynamically allocate a new Block object, construct a SPtr with a pointer to
// the dynamically allocated Block object, and return a stack-allocated new
// Blockchain object initialized with the SPtr

Blockchain Blockchain::extend() {
	SPtr p = SPtr( new Block( &sp ) );
	return Blockchain( &p );
}

ostream& Blockchain::print( ostream& out ) const {
	sp.target_ptr()->printChain( out );
	return out;
}

Blockchain& Blockchain::operator=( Blockchain other ) {
	sp = other.sp;
	return *this;
}
