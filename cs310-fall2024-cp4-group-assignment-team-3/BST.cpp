#include "BST.h"
#include "MaxHeap.h"
#include "Trisha.h"

BST::BST(){
  root = nullptr;
  heapIndexCounter = 0;
}

BST::BSTNode* BST::insert(Voter passedInVoter){
  if (root == nullptr){// for first voter
    root = new BSTNode(passedInVoter, heapIndexCounter);
    heapIndexCounter++;
    return root;
  }
  else{
    insertNode(passedInVoter, root);
    return nodeToReturn;
  }
}
  

BST::BSTNode* BST::insertNode(Voter passedInVoter, BSTNode * root){
  if (root == nullptr){
    BSTNode * newNode = new BSTNode(passedInVoter, heapIndexCounter);
    //theTrisha.TrishasMaxHeap->HeapArrayElement(0, heapIndexCounter, root);
    heapIndexCounter++;
    //theTrisha.TrishasLinkedListVector->insertNode() //this could be VERY wrong or not named right. Should be creating node in linked list
    return newNode;
  }		 
  if (passedInVoter.firstName > root->voter_data.firstName){ // doesn't quite actually mean root, root of the subtree in the recursion
    BSTNode * temp = insertNode(passedInVoter, root->right_child_BST);
    root->right_child_BST = temp;
    nodeToReturn = temp;

  } else {	
    BSTNode * temp = insertNode(passedInVoter, root->left_child_BST);
    root->left_child_BST = temp;
    nodeToReturn = temp;
  }
}


int BST::removeNode(string firstName, string lastName, BSTNode* root){
  BSTNode * nodeToRemove = find(firstName, lastName, root);
  //MaxHeap::RemoveFromHeap(nodeToRemove->heapIndex);
  int indexToReturn = nodeToRemove->heapIndex;
  heapIndexCounter--;
  nodeToRemove->heapIndex = -1;
  return indexToReturn;
}

BST::BSTNode* BST::find(string firstName, string lastName, BSTNode* root){
  BST::BSTNode* rootToReturn;
  if (root->voter_data.firstName < firstName){
    return find(firstName, lastName, root->right_child_BST);
  }else if(root->voter_data.firstName > firstName){
    return find(firstName, lastName, root->left_child_BST);
  }else{
    if(root->voter_data.lastName < lastName){
      return find(firstName, lastName, root->right_child_BST);
    }else if(root->voter_data.lastName > lastName){
      return find(firstName, lastName, root->left_child_BST);
    }else{
      rootToReturn = root;
    }
  }
  return rootToReturn;
}

bool BST::findVoter(string firstName, string lastName, BSTNode* root){
  while (root != nullptr){
    if (root->voter_data.firstName < firstName){
      return findVoter(firstName, lastName, root->right_child_BST);
    }else if(root->voter_data.firstName > firstName){
      return findVoter(firstName, lastName, root->left_child_BST);
    }else{
      if(root->voter_data.lastName < lastName){
	return findVoter(firstName, lastName, root->right_child_BST);
      }else if(root->voter_data.lastName > lastName){
	return findVoter(firstName, lastName, root->left_child_BST);
      }else{
	return true;
      }
    }
  }
  return false;
}
