/* ----------------------------------------------------------------------------
 * Block class header                                                 Block.hpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Cheng Luo
 *       NetID: cl2247
 *    Modified: Dec 9, 2018
 * ----------------------------------------------------------------------------
 * Header file for the Block class that models after a single block in a
 * blockchain.
 */

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include "SPtr.hpp"
#include "tools.hpp"
#include "BlockSerial.hpp"

class Block {
private:
	const int serialNo;
	const int level;
	const SPtr sp;

	static bool genesis_initialized;

	Block( const Block& other ) = delete;
	Block& operator=( const Block& other ) = delete;

	Block() : serialNo(BlockSerial::newID()), level(0), sp() {
	}

public:
	Block( SPtr* prev ) : serialNo(BlockSerial::newID()),
		level(prev->target_ptr()->blkLevel() + 1), sp(*prev) {}
	~Block() = default;
	static Block* init_genesis() {
		if (genesis_initialized) fatal( "Multiple Genesis block" );
		genesis_initialized = true;
		Block* bp = new Block();
		return bp;
	}
	int blkLevel() const { return level; }

	bool equals( Block* other ) { return serialNo == other->serialNo; }
	bool smaller( Block* other ) {
		if (level != other->level) {
			return level < other->level;
		}
		else {
			return serialNo > other->serialNo;
		}
	}

	std::string print() const;
	std::ostream& print( std::ostream& out ) const;

	std::ostream& printChain( std:: ostream& out ) const;

};

inline std::ostream& operator<<( std::ostream& out, const Block& bl ) {
	return bl.print( out );
}


#endif /* BLOCK_HPP */
