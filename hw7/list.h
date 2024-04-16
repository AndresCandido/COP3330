// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   List(const List& other); // copy constructor ------------- my function
   ~List();     // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );

    // my functions:
   void insertMiddle( const NODETYPE & , int x);
   bool removeMiddle( NODETYPE & , int x);
   List<NODETYPE>& operator=(const List& other);

   bool isEmpty() const;
   void print() const;

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   int num_nodes;

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List() : firstPtr( 0 ), lastPtr( 0 ), num_nodes(0){ 
  // empty body

} // end List constructor

// copy constructor ----------------------------------------------------------------------------- my function
template< class NODETYPE >
List< NODETYPE >::List(const List& other) : firstPtr( 0 ), lastPtr( 0 ) {

   num_nodes=0;

   ListNode<NODETYPE>* current = other.firstPtr;


   while (current != 0) {
      insertAtBack(current->data);
      current = current->nextPtr;
      num_nodes++;
   }
}


// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {  
         tempPtr = currentPtr;

// commented out the output -- no need to print what we are deallocating
//         cout << tempPtr->data << '\n';  

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;

      }

   }

//   cout << "All nodes destroyed\n\n";

} // end List destructor

// Assignment operator overload ------------------------------------------------------------------------ my function
template <class NODETYPE>
List<NODETYPE>& List<NODETYPE>::operator=(const List& other) {

   // Delete the current list
   while (!isEmpty()) {
      NODETYPE value;
      removeFromFront(value);
   }
   num_nodes=0;

   // Copy the other list
   ListNode<NODETYPE>* current = other.firstPtr;

   while (current != 0) {
      insertAtBack(current->data);
      current = current->nextPtr;
      num_nodes++;
   }
   
   return *this;
}

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else

   num_nodes += 1;

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else

   num_nodes += 1;

} // end function insertAtBack

// insert node at selected position ------------------------------------------------------------------------- my function
template< class NODETYPE >
void List< NODETYPE >::insertMiddle( const NODETYPE &value, int x){

   if ( isEmpty() || x<=1){  // Insert at the front if List is empty or desired position is first ( or if position is invalid (too small) )
      insertAtFront(value);
   }
   else if (x > num_nodes) { // Insert at the back if desired position is last or if position is invalid (too large)
      insertAtBack(value);
   }
   else {
      ListNode< NODETYPE > *newPtr = getNewNode( value );
      ListNode< NODETYPE > *previousPtr = 0;
      ListNode< NODETYPE > *currentPtr = firstPtr;
      int currentPos = 1;

      // loop until desired position is reached
      while (currentPos < x){
         currentPos++;

         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }

      // Insert the new node at desired position in the list
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;

      num_nodes += 1; // increase number of nodes by 1
   }
}

// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      num_nodes -= 1;

      return true;  // delete successful

   } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      num_nodes -= 1;

      return true;  // delete successful

   } // end else

} // end function removeFromBack

// remove node from specified position in list ------------------------------------------------------------------------- my function
template< class NODETYPE >
bool List< NODETYPE >::removeMiddle(NODETYPE& value, int x) {
   if (isEmpty()) {
      return false;
   }
   else if(x <= 0 || x > num_nodes){
      return false;
   }
   else{
      // Traverse the list to find the node to remove
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *previousPtr = 0;
      int currentPos = 1;
      while (currentPos < x) {
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
         currentPos++;
      }

      // Remove the node from the middle of the list
      value = currentPtr->data;
      if (currentPtr == firstPtr) {
         removeFromFront(value);
      } else if (currentPtr == lastPtr) {
         removeFromBack(value);
      } else {
         previousPtr->nextPtr = currentPtr->nextPtr;
         delete currentPtr;
      }

      num_nodes -= 1;
      return true;
   }
}

// is List empty?
template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
   
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * "DISCLAIMER": The authors and publisher of this book have used their   *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/