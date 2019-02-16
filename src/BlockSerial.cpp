/* ----------------------------------------------------------------------------
 * BlockSerial class implementation                             BlockSerial.cpp
 *
 *  Created on: Dec 2, 2018
 *      Author: Cheng Luo, Mike
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Function definitions for the BlockSerial class that is used to assign a
 * unique id starting from 1 to each block in the blockchain problem. This class
 * is identical to the given Serial class.
 */

#include "BlockSerial.hpp"

// Initialize Serializer static variable
BlockSerial* BlockSerial::Sobj = nullptr;


