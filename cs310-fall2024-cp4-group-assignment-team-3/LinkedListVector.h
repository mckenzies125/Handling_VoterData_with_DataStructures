#ifndef _H_LinkedListVector_
#define _H_LinkedListVector_

#include "BST.h"
#include <vector>

class LinkedListVector{
public:
  int linkedListVectorIndex;
  LinkedListVector();
  
  class LinkedList{
  public:
    
    class LinkedListNode{
    public:
      
      BST::BSTNode * pointerToBST;
      LinkedListNode * nextNode;
      
      LinkedListNode(BST::BSTNode * passedInNode);
    };

    LinkedListNode * head;
    LinkedListNode * tempNode;
    
    void insertNode(BST::BSTNode * passedInNode);
    
    void makeALinkedList(BST::BSTNode * passedInNode);
  };
  
  std::vector<LinkedList> TrishasLinkedListVector;
  
  void insertIntoVector(BST::BSTNode * BSTpointer, int age);
  void printVoters();
};

#endif
