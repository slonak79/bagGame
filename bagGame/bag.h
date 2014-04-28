// FILE: bag1.h
// CLASS PROVIDED: bag
//
// MEMBER CONSTANTS for the bag class:
//   const int CAPACITY = _____
//     bag::CAPACITY is the maximum number of items that a bag can hold.
//
// CONSTRUCTOR for the bag class:
//   bag( )
//     Postcondition: The bag has been initialized as an empty bag with 0 used.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   int erase(int target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(int target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(int entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   int size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
//   int count(int target) const
//     Postcondition: The return value is number of times target is in the bag.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with bag objects.

#ifndef BAG1_H
#define BAG1_H

class Bag
{
public:
    // MEMBER CONSTANTS
    static const int CAPACITY = 30;
    // CONSTRUCTOR
    Bag();
    // MODIFICATION MEMBER FUNCTIONS
    int erase(int target);
    bool erase_one(int target);
    void insert(int entry);
    // CONSTANT MEMBER FUNCTIONS
    int size( ) const;
    int count(int target) const;
    int showOne(int);
    
    
private:
    int data[CAPACITY];  // The array to store items
    int used;             // How much of array is used
};

#endif
