/*
Ali Burak ERDOĞAN
21301492
CS202 - Section 3
Homework#3
*/
/** @file Heap.cpp */
#include <iostream>
using namespace std;

#include "Heap.h"  // header file for class Heap

Heap::Heap() : size(0)
{
}  // end default constructor

Heap::~Heap()
{
}  // end destructor

bool Heap::heapIsEmpty() const
{
   return bool(size == 0);
}  // end heapIsEmpty

void Heap::heapInsert( HeapItemType*& newItem)
   throw(HeapException)
// Method: Inserts the new item after the last item in the
// heap and trickles it up to its proper position. The
// heap is full when it contains MAX_HEAP items.
{
   if (size >= MAX_HEAP)
      throw HeapException("HeapException: Heap full");
   // place the new item at the end of the heap
   items[size] = newItem;

   // trickle new item up to its proper position
   int place = size;
   int parent = (place - 1)/2;
   while ( (parent >= 0) &&
           (items[place]->getPriority() > items[parent]->getPriority()) )
   {  // swap items[place] and items[parent]
      HeapItemType* temp = items[parent];
      items[parent] = items[place];
      items[place] = temp;

      place = parent;
      parent = (place - 1)/2;
   }  // end while

   ++size;
}  // end heapInsert

void Heap::heapDelete(HeapItemType*& rootItem)
   throw(HeapException)
// Method: Swaps the last item in the heap with the root
// and trickles it down to its proper position.
{
   if (heapIsEmpty())
      throw HeapException("HeapException: Heap empty");
   else
   {  rootItem = items[0];
      items[0] = items[--size];
      heapRebuild(0);
   }  // end if
}  // end heapDelete

void Heap::heapRebuild(int root)
{
   // if the root is not a leaf and the root's search key
   // is less than the larger of the search keys in the
   // root's children
   int child = 2 * root + 1;  // index of root's left
                              // child, if any
   if ( child < size )
   {  // root is not a leaf, so it has a left child at child
      int rightChild = child + 1;  // index of right child,
                                   // if any

      // if root has a right child, find larger child
      if ( (rightChild < size &&
           items[rightChild]->getPriority() > items[child]->getPriority()) ||  (items[rightChild]->getPriority() == items[child]->getPriority()
            && items[rightChild]->getRequestTime() < items[child]->getRequestTime()) )
         child = rightChild;  // index of larger child

      // if the root's value is smaller than the
      // value in the larger child, swap values
      if ( items[root]->getPriority() < items[child]->getPriority() || (items[root]->getPriority() == items[child]->getPriority()
            && items[root]->getRequestTime() > items[child]->getRequestTime()) )
      {  HeapItemType* temp = items[root];
         items[root] = items[child];
         items[child] = temp;

         // transform the new subtree into a heap
         heapRebuild(child);
      }  // end if
   }  // end if

   // if root is a leaf, do nothing
}  // end heapRebuild

void Heap::printHeap()
{
    cout << "Current heap is: ";
    for(int i = 0; i < size; i++)
        cout << items[i]->getId() << " ";
}
// End of implementation file.
