#ifndef TRISHA_H
#define TRISHA_H

#include "BST.h"
#include "LinkedListVector.h"
#include "MaxHeap.h"
/*

BST.cpp BST.h

same for others


Trisha.h

class Trisha {

  private:
	BST BST_obj;
        Maxheap Maxheap_obj;
        LinkedList LL_obj;


  public:
       insert_to_Trisha( Voter x ){
          BST_Node* added_bst_node_ptr = BST_obj.insert( x );
          int add_heap_node_index = Maxheap_obj.add( x );
          added_best_node_ptr->add_corresponding_head_index( add_heap_node_index );


	}



*/




class Trisha {
  /*private:
  class BST{
  public:
    BSTNode * root;
    BSTNode * currNode;
    
    class BSTNode{
    public:
      Voter voter_data;
      BSTNode * left_child_BST;
      BSTNode * right_child_BST;
	int heapIndex;
      
      BSTNode(const Voter &passedInVoter){
	voter_data = passed_in_voter;
	left_child_BST = nullptr;
	right_child_BST = nullptr;
	int heapIndex = -1;
	//if (currNode.voter_data.firstName > root.voter_data.firstName)
	//HeapArray(0, heapIndex, ); // third parameter should be a pointer, it should point to the BSTNode this item in the max heap at heapIndex needs to point to in the BST
	//heapIndex++;
      }

      
    };

	BST(){
		root = nullptr;
	};
    BSTNode * insertNode(const Voter &passedInVoter, BSTNode * root){
      if (root == nullptr){
	BSTNode * newNode = BSTNode(passedInVoter);
	HeapArrayElement(0, heapIndex, root);
	heapIndex++;
	TrishasLinkedList.insertNode() //this could be VERY wrong or not named right. Should be creating node in linked list
	return newNode;
      } 
	if (passedInVoter.firstName > root->voter_data.firstName){ // doesn't quite actually mean root, root of the subtree in the recursion
	  root->right_child_BST = insertNode(passedInVoter, root->right_child_BST);
	} else {
	  root->left_child_BST = insertNode(passedInVoter, root->left_child_BST);
	}
      }
  };
  class MaxHeap{
  public:
    
    // Make Vector
	//potentially make a constructor, but vector doesn't need one and heap is made from vector
    std::vector<int> TrishasHeapArray;
    int HeapArraySize = 0;
    int HeapArrayCap = 1;
    int currNodeIndex;
    BSTNode * pointerToBSTNode;
    //class HeapNode{
      //public:
      //BSTNode * pointToBSTNode;
      //Voter voter_data;
      //HeapNode * left_child_heap;
      //HeapNode * right_child_heap;
      //BSTNode * pointToBSTNode;
      //int impactVal = 0;
      //int strength = 0;
      //int likelihood = 0;  
	MaxHeap(){
		currNodeIndex = 0;	
	}      
    HeapArrayElement(const int passed_in_impact, int indexInVector, const BSTNode * BSTNode){
      currNodeIndex = indexInVector;
      TrishasHeapArray[currNodeIndex].impactVal = passed_in_impact; // read up on vector implementation (where each element in vector stores more than one piece of info)
      TrishasHeapArray[currNodeIndex].pointerToBSTNode = BSTNode;
      //left_child_heap = nullptr;
      //right_child_heap = nullptr;
      //currNodeIndex = HeapArraySize; // Make currNodeIndex the last node in the heap
      // Voter.index= currNodeIndex; // Set voter object's index var equal to what is inside of currNodeIndex
      
      //For percolate
      if (HeapArraySize > 0){
	int parentNodeIndex = (currNodeIndex - 1)/2;
	while (TrishasHeapArray[parentNodeIndex].impactVal < TrishasHeapArray[currNodeIndex].impactVal){
	  //For Swap//
	  // For swaping indexes
	  //int tempindex = currNodeIndex; //Maybe
	  //currNodeIndex = parentNodeIndex;
	  //parentNodeIndex = tempIndex;

	  // sets current Node's impact and pointer back to BST in temp variables
	  int tempImpactVal = TrishasHeapArray[currNodeIndex].impactVal;  
	  BSTNode * temp = TrishasHeapArray[currNodeIndex].pointerToBSTNode;

	  // swapping
	  TrishasHeapArray[currNodeIndex].impactVal = TrishasHeapArray[parentNodeIndex].impactVal;
	  TrishasHeapArray[currNodeIndex].pointerToBSTNode = TrishasHeapArray[parentNodeIndex].pointerToBSTNode;

	  TrishasHeapArray[parentNodeIndex].impactVal = tempImpactVal;
	  TrishasHeapArray[parentNodeIndex].pointerToBSTNode = temp;

	  // delete temp pointer
	  delete temp;

	  // using pointer to trace back to BST where we update the index in the BSTNode
	  (* TrishasHeapArray[currNodeIndex].pointerToBSTNode).heapIndex = parentNodeIndex;
	  (* TrishasHeapArray[parentNodeIndex].pointerToBSTNode).heapIndex = currNodeIndex;
	  // For Regular Percolate
	}
      }
      heap_index = HeapArraySize; // Back to top
      heap_index++; // So next one is put at the next index :)
      HeapArraySize++;
    }
  };

  class LinkedListVector{
  public:
	LinkedListVector(){
		std::vector<int> TrishasLinkedListVector(100);
    		int linkedListVectorIndex;
    	}
    class LinkedList{
    public:
      LinkedListNode * head;
      LinkedListNode * tempNode;
      
      class LinkedListNode{
	BSTNode * pointerToBST;
	LinkedListNode * nextNode;

	LinkedListNode(const BSTNode * passedInNode){//pointer
	  pointerToBST = passedInNode;
	  nextNode = nullptr;
	}
      };

      insertNode(const BSTNode * passedInNode){
	if (head == nullptr){
	  head = LinkedListNode(const BSTNode * passedInNode);
	} else {
	  tempNode = head;
	  head = LinkedListNode(const BSTNode * passedInNode);
	  head->nextNode = tempNode;
	}
      }
	makeALinkedList(const BSTNode * passedInNode){
		insertNode(BSTNode * passedInNode);
	}
    };
	insertIntoVector(const BSTNode * BSTpointer, int age){ //takes in pointer to bst node and voter's age (voter.age)
		linkedListedVectorIndex = age - 18;
		TrishasLinkedList[linkedListVectorIndex].makeALinkedList(BSTpointer);
	}
  };
*/

  public:
  Trisha();
  //  Trisha(const Trisha &other);
  //  Trisha &operator=(const Trisha &other);
  //  ~Trisha();

  BST * TrishasBST;
  MaxHeap * TrishasMaxHeap;
  LinkedListVector * TrishasLinkedListVector;

  int heapIndexCounter;
  
  // figure out parameters for the following
  bool voter(string firstName, string lastName, int Age); // returns true if added, returns false if exists already
  void voted(string firstName, string lastName, int age); // set vote_status to true
  void support(string firstName, string lastName, int strengthVal);
  void reduce_likelihood(string firstName, string lastName, double likelihoodVal);
  bool chauffeur(); // returns true after chauffering a voter, false if max-heap is empty
  void show_impact();
};

#endif


    /*MEETING LOG AND TASKS
      
      NOV 13
      COMPLETED TASKS
      - Began work on swap and percolate and created the data members for HeapNodes
      ACTION ITEMS:
      - Decide which data structure holds the index.
      - What data does the heap have access to and how is it passed
      - Finish Percolate

      NOV 15
      Worked on changing how Vector and BST interact with each other. 
      Need to read up on swapping vector elements (when each element has more than one variable to keep track of)
      Need to implement following back the pointer to the BST and updating the heapIndex value in the BSTNode (read up!)

      NOV 17
      I believe we did BST tree and Heap array correctly *fingers crossed*
      ACTION ITEMS:
      - Start third data structure (array/vector that serves as the head of a linked list where the index is the age - 18, and the linked list will store a pointer to the respective BSTNode in the BST)
    NOV 18
	- Created vector and linked list that is within the vector (lines 108-145)!
	ACTION ITEMS:
	- Debug data structures (they're gonna need it lol save us plz)
	- start on functions (hopefully they won't be too bad)
	 */
