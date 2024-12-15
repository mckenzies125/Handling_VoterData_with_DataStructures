#ifndef _H_BST_
#define _H_BST_

#include "Voter.h"

class BST{
public:
  BST();
  ~BST(); // TODO
  
  class BSTNode{
  public:
    Voter voter_data;
    BSTNode * left_child_BST;
    BSTNode * right_child_BST;
    int heapIndex;
    
    BSTNode(Voter passedInVoter, int heapIndexIterator){
      voter_data = passedInVoter;
      left_child_BST = nullptr;
      right_child_BST = nullptr;
      heapIndex = heapIndexIterator;
    }
  };

  BSTNode * root;
  BSTNode * currNode;
  int heapIndexCounter;
  BSTNode * nodeToReturn;
  
  BSTNode* insert(Voter passedInVoter);
  BSTNode* insertNode(Voter passedInVoter, BSTNode * root);
  int removeNode(string firstName, string lastName, BSTNode* root);
  BSTNode* find(string firstName, string lastName, BSTNode* root);
  bool findVoter(string firstName, string lastName, BSTNode* root);
};

#endif
