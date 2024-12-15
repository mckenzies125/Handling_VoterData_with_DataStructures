#include "Trisha.h"
#include "Voter.h"
#include <iostream>
using namespace std;

Trisha::Trisha(){
  TrishasBST = new BST();
  TrishasMaxHeap = new MaxHeap();
  TrishasLinkedListVector = new LinkedListVector();
  heapIndexCounter = 0;
}

// RULE OF 3 (MAYBE NEED? IDK)
//Trisha::Trisha(const Trisha &other){
//
//}
//Trisha &Trisha::operator=(const Trisha &other){
//
//}
//Trisha::~Trisha(){
//
//}

// FUNCTIONALITIES OF TRISHA //

//VOTER//
bool Trisha::voter(string firstName, string lastName, int Age){
  if((Age < 18) || (Age > 118)){
    return false;
  }else{
    if (!TrishasBST->findVoter(firstName, lastName, TrishasBST->root)){
      Voter * voter = new Voter(firstName, lastName, Age); //make voter cobstructor
      //for debugging
      BST::BSTNode* insertedNode = TrishasBST->insert(*voter);
      TrishasMaxHeap->HeapArrayElement(voter->impactVal, heapIndexCounter, insertedNode);
      TrishasLinkedListVector->insertIntoVector(insertedNode, Age);
      
      heapIndexCounter++;
      cout << "New voter " << firstName << " " << lastName << ", age " << Age << ", added." << endl;
      return true;
    }else {
      cout << "Voter " << firstName << " " << lastName << ", age " << Age << ", already exists." << endl;
      return false;
    }
  }
} 

//VOTED//
// returns true if added, returns false if exists already
void Trisha::voted(string firstName, string lastName, int age){
  int heapIndexToRemove = TrishasBST->removeNode(firstName, lastName, TrishasBST->root);
  if (heapIndexToRemove == -1){
    cout << firstName << " " << lastName << " already voted." << endl;
  }else{
    TrishasMaxHeap->RemoveFromHeap(heapIndexToRemove);
    heapIndexCounter--;
    cout << "Voter " << firstName << " " << lastName << ", age " << age << ", voted" << endl;
  }
} // set vote_status to true


//SUPPORT//
// Increasing support of voter
void Trisha::support(string firstName, string lastName, int passedInStrengthVal){
  BST::BSTNode * rootOfBST = TrishasBST->root;
  BST::BSTNode * nodeToUpdate = TrishasBST->find(firstName, lastName, rootOfBST);
  //Voter nodeToUpdateData = nodeToUpdate->voter_data;
  nodeToUpdate->voter_data.strengthVal += passedInStrengthVal;
  nodeToUpdate->voter_data.impactVal = nodeToUpdate->voter_data.strengthVal / nodeToUpdate->voter_data.likelihoodVal; 
  int retrievedIndex = nodeToUpdate->heapIndex;
  TrishasMaxHeap->updateHeapNodeImpactVal(retrievedIndex, nodeToUpdate->voter_data.impactVal); //this was added
  TrishasMaxHeap->PercolateUp(retrievedIndex);
  cout << "Support from " << firstName << " " << lastName << " increased by " << passedInStrengthVal << " strength points.\n";

}


//REDUCE LIKELIHOOD//                                                                                                                                                                      
// Reduce likelihood of voter

void Trisha::reduce_likelihood(string firstName, string lastName, double passedInLikelihoodVal){
  BST::BSTNode * rootOfBST = TrishasBST->root;
  BST::BSTNode * nodeToUpdate = TrishasBST->find(firstName, lastName, rootOfBST);
  //Voter nodeToUpdateData = nodeToUpdate->voter_data;
  (nodeToUpdate->voter_data.likelihoodVal) = (nodeToUpdate->voter_data.likelihoodVal) * (1 - (passedInLikelihoodVal / 100));
  nodeToUpdate->voter_data.impactVal = nodeToUpdate->voter_data.strengthVal / nodeToUpdate->voter_data.likelihoodVal; 
  //cout << nodeToUpdate->voter_data.likelihoodVal << endl;
  int retrievedIndex = nodeToUpdate->heapIndex;
  TrishasMaxHeap->updateHeapNodeImpactVal(retrievedIndex, nodeToUpdate->voter_data.impactVal); //this was added
  TrishasMaxHeap->PercolateUp(retrievedIndex);

  cout << "Voting likelihood of " << firstName << " " << lastName << " decreased by " << passedInLikelihoodVal << "%" << endl;  
}

bool Trisha::chauffeur(){
  if (TrishasMaxHeap->TrishasHeapArray.empty()){
    return false;
  }else {
    BST::BSTNode * nodeToPrint = TrishasMaxHeap->RemoveFromHeap(0);
    heapIndexCounter--;
    cout << "Driving " << nodeToPrint->voter_data.firstName << " " << nodeToPrint->voter_data.lastName << " (" << nodeToPrint->voter_data.age << "): strength of support: " << nodeToPrint->voter_data.strengthVal << ", likelihood: " << nodeToPrint->voter_data.likelihoodVal << ", impact: " << nodeToPrint->voter_data.impactVal << endl;
    return true;
  }
} // returns true after chauffering a voter, false if max-heap is empty
//Extract-max function "chauffer" remember to decrement heapIndex from BST class to account for the empty space

//SHOW IMPACT//
// print out all the voters 
void Trisha::show_impact(){
  TrishasLinkedListVector->printVoters();  
  //cout << "byyyye" << endl;
}
