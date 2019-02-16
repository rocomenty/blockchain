/*
 * SPtr.cpp
 *
 *  Created on: Nov. 11, 2018
 *      Author: mike
 *
 * Modified on: Nov. 27, 2018 and Dec 9, 2018
 *  	Author: Cheng Luo
 *  	 NetID: cl2247
 */

#include "SPtr.hpp"
#include "Block.hpp"

// Default constructor
SPtr::SPtr() : count(nullptr), target(nullptr) {
	if (!empty() && DEBUG) {
		cout << "  Default constructor called for Sptr " << id() << endl;
	}
}

// Construct an SPtr to manage p
SPtr::SPtr(T* p) : count(new unsigned(1)), target(p) {
	if (!empty() && DEBUG) {
		cout << "  SPtr(T*) constructor called for Sptr " << id() <<
				" to address: " << target << " count: " << *count << endl;
	}
}

//------------------------------------------------------------------------------
// Copy constructor
SPtr::SPtr(const SPtr& sp) : count(sp.count), target(sp.target) {
    ++*count;
    if (!empty() && DEBUG) {
    	cout << "  Copy constructor from Sptr " << sp.id() << " to " << id() <<
    			" to address: " << target << " count: " << *count << endl;
    }
}

//------------------------------------------------------------------------------
// Copy assignment
SPtr&
SPtr::operator=(const SPtr& sp) {
    reset();
    count = sp.count;
    target = sp.target; // copy pointer
    ++*count;
    if (!empty() && DEBUG) {
    	cout << "  Copy assignment from Sptr " << sp.id() << " to " << id() <<
    			" to address: " << target << " count: " << *count << endl;
    }
    return *this;
}

//------------------------------------------------------------------------------
// Move constructor
SPtr::SPtr(SPtr&& sp) : count(sp.count), target(sp.target) {
    sp.count = nullptr;
    sp.target = nullptr;
    if (!empty() && DEBUG) {
    	cout << "  Move constructor from Sptr " << sp.id() << " to " << id() <<
    			" to address: " << target << " count: " << *count << endl;
    }
}

//------------------------------------------------------------------------------
// Move assignment
SPtr& SPtr::
operator=(SPtr&& sp) {
    reset();
    count = sp.count;
    target = sp.target;
    sp.count = nullptr;
    sp.target = nullptr;
    if (!empty() && DEBUG) {
    	cout << "  Move assignment from Sptr " << sp.id() << " to " << id() <<
    			" to address: " << target << " count: " << *count << endl;
    }
    return *this;
}

//------------------------------------------------------------------------------
// Unmanage target if currently being managed and adjust count.
// If count falls to 0, delete count and target.
// Afterwards, *this is back in its default empty state.
void SPtr::reset() {
    if (empty()) {
    	if (DEBUG) cout << "empty reset" << endl;
    	return;        // already empty; nothing to do
    }
    // Unmanage target pointer
    if (--*count > 0) {
    	if (DEBUG) cout << "   count still > 0; to address: " << target <<
    			" count: " << *count << endl;
    	return;
    }
    // No other references, so release managed storage
    if (RELEASE_INFO) cout << "  Releasing storage managed by Sptr " << id() <<
    		" to address: " << target << " count: " << *count << endl;
    delete count;
    delete target;
    count = nullptr;
    target = nullptr;
}

