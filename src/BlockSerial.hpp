/* ----------------------------------------------------------------------------
 * BlockSerial class header                                     BlockSerial.hpp
 *
 *  Created on: Dec 2, 2018
 *      Author: Cheng Luo, Mike
 *       NetID: cl2247
 * ----------------------------------------------------------------------------
 * Header file for the BlockSerial class that is used to assign a unique id
 * starting from 1 to each block in the blockchain problem. This class is
 * identical to the given Serial class.
 */

#ifndef BLOCKSERIAL_HPP_
#define BLOCKSERIAL_HPP_

class BlockSerial {
private:
   static BlockSerial* Sobj; // pointer to singleton Serial object
   int nextUID=1;       // data member for next UID to be assigned
   static BlockSerial* uidGen() {  // instaniates Serial on first call
      if (Sobj == nullptr) Sobj = new BlockSerial;
      return Sobj;
   }
   BlockSerial() =default;   // private constructor prevents external instantiation
public:
   static int newID() { return uidGen()->nextUID++; }
};



#endif /* BLOCKSERIAL_HPP_ */
