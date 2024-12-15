#ifndef _H_MaxHeap_
#define _H_MaxHeap_

#include "BST.h"
#include <vector>

class MaxHeap{
public:
  //potentially make a constructor, but vector doesn't need one and heap is made from vector
  struct HeapNode {
    double impactVal;
    BST::BSTNode * pointerToBSTNode;
  };

  MaxHeap();

  std::vector<HeapNode> TrishasHeapArray;
  int currNodeIndex;
  int heapIndexCounter;

  void HeapArrayElement(int passed_in_impact, int indexInVector, BST::BSTNode * node);
  void PercolateUp(int curNodeIndex);
  BST::BSTNode * RemoveFromHeap(int indexInVector);
  void updateHeapNodeImpactVal(int index, double newImpactVal);
};

/*
within MaxHeap class:
std::vector<HeapNode> TrishasHeapArray;
int currNodeIndex;

struct HeapNode {
	int impactVal;
	BSTNode * pointerToBSTNode;
}
*/

#endif
