/*
 * SPtr.hpp
 *
 *  Created on: Feb 25, 2016
 *      Author: mike
 *
 *  Modified on: Nov 27, 2018 and Dec 9, 2018
 *  	Author: Cheng Luo
 *  	 NetID: cl2247
 */

#ifndef SPTR_HPP_
#define SPTR_HPP_

#include <iostream>
#include <exception>

#include "Serial.hpp"
class Block;

using namespace std;
using T = Block;

const bool DEBUG = false;
const bool RELEASE_INFO = false;

// ----------------------------------------------------------------------------
// Smart pointer exception class
class SPexception : std::exception {
private:
    string s;
public:
    SPexception( string s ) : s(s) {}
    virtual const char* what() const noexcept { return s.data(); }
};

// ----------------------------------------------------------------------------
// Smart pointer class
class SPtr {
private:
    unsigned* count = 0;    // shared object among all SPtr with same target
    T* target = nullptr;    // shared target object
    const int my_id = Serial::newID();    // assign unique ID to each instance

public:
    // Default constructor
    SPtr();
    // Construct an SPtr to manage p
    SPtr(T* p);
    // Copy constructor
    SPtr(const SPtr& sp);
    // Copy assignment
    SPtr& operator=(const SPtr& sp);
    // Move constructor
    SPtr(SPtr&& sp);
    // Move assignment
    SPtr& operator=(SPtr&& sp);
    // Destructor
    ~SPtr() {
    	if (!empty() && DEBUG) {
    		cout << "  Destructor called for SPtr " << id() <<  "target: "
    				<< target << " count: " << *count - 1 << endl;
    	}
        reset();
    }

    bool empty() const { return count==nullptr; };
    void reset();
    int id() const { return my_id; }

    // Follow operator.
    T& operator*() {
        if (!empty()) return *target;
        else throw SPexception("Can't follow empty SPtr");
    }

    T* target_ptr() const {
    	return target;
    }

    void print() const {
    	if (!empty() && DEBUG) {
    		std::cout << "target: " << target << " id: " << id() <<
    				" count: " << *count << std::endl;
    	}
    }
};

#endif /* SPTR_HPP_ */
