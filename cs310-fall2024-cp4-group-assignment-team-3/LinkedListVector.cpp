#include "LinkedListVector.h"
LinkedListVector::LinkedListVector() : TrishasLinkedListVector(101){
  
}

LinkedListVector::LinkedList::LinkedListNode::LinkedListNode(BST::BSTNode * passedInNode){//pointer
  pointerToBST = passedInNode;
  nextNode = nullptr;
}

void LinkedListVector::LinkedList::insertNode(BST::BSTNode * passedInNode){
  if (head == nullptr){
    head = new LinkedListNode(passedInNode);
  } else {
    LinkedListNode * tempNode = head;
    head = new LinkedListNode(passedInNode);
    head->nextNode = tempNode;
  }
}
// maybe unecessary, given that insertNode does the same thing?
void LinkedListVector::LinkedList::makeALinkedList(BST::BSTNode * passedInNode){
  insertNode(passedInNode);
}

void LinkedListVector::insertIntoVector(BST::BSTNode * BSTpointer, int age){
  linkedListVectorIndex = age - 18;
  TrishasLinkedListVector[linkedListVectorIndex].makeALinkedList(BSTpointer);
}

void LinkedListVector::printVoters(){
  for(int i = 0; i < 101; i++){
    LinkedList &currentList = TrishasLinkedListVector[i];
    if(currentList.head != nullptr){
      LinkedList::LinkedListNode * curr = currentList.head;
      
      //error after printing this
      while(curr != nullptr){
	      string firstName = curr->pointerToBST->voter_data.firstName;
	      string lastName = curr->pointerToBST->voter_data.lastName;
        if (curr->pointerToBST->heapIndex >= 0){
	        cout << firstName << " " << lastName << " (" << (i+18) << "): strength of support: " << curr->pointerToBST->voter_data.strengthVal << ", likelihood: " << curr->pointerToBST->voter_data.likelihoodVal << ", impact: " << curr->pointerToBST->voter_data.impactVal << "\n";
        }
        curr = curr->nextNode;
      }
    }
  }
  
}
