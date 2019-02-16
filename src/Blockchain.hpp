/* ----------------------------------------------------------------------------
 * Blockchain class header                                       Blockchain.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 11, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Blockchain class that models after a single blockchain.
 */

#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "Block.hpp"

class Blockchain {
private:
	SPtr sp;
	Block* tail() { return sp.target_ptr(); };

public:
	Blockchain( SPtr* bp ) : sp( *bp ) {}
	Blockchain( const Blockchain& other ) : sp(other.sp) {}
	Blockchain extend();
	bool operator==( const Blockchain& other ) const {
		return sp.target_ptr()->equals( other.sp.target_ptr() );
	}
	bool operator<( const Blockchain& other ) const {
		return sp.target_ptr()->smaller( other.sp.target_ptr() );
	}
	bool operator!=( const Blockchain& other ) const {
		return !sp.target_ptr()->equals( other.sp.target_ptr() );
	}
	~Blockchain() = default;
	unsigned length() const { return sp.target_ptr()->blkLevel(); }
	Blockchain& operator=( Blockchain other );
	ostream& print( ostream& out ) const;
};

inline ostream& operator<<( ostream& out, const Blockchain& bc ) {
	return bc.print( out );
}

#endif /* BLOCKCHAIN_HPP */
