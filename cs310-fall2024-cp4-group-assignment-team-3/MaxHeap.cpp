#include "MaxHeap.h"

MaxHeap::MaxHeap(){
  currNodeIndex = 0;
  heapIndexCounter = 0;	
};

void MaxHeap::HeapArrayElement(int passed_in_impact, int indexInVector, BST::BSTNode * node){
  // this was here from when we were dealing with currNodeIndex in BST::insert, so probably shouldn't be here
  currNodeIndex = indexInVector;
  MaxHeap::HeapNode nodeHeapArray;
  nodeHeapArray.impactVal = passed_in_impact;
  //TrishasHeapArray[currNodeIndex].impactVal = passed_in_impact;
  nodeHeapArray.pointerToBSTNode = node;
  //TrishasHeapArray[currNodeIndex].pointerToBSTNode = node;

  TrishasHeapArray.push_back(nodeHeapArray);
  
  //For percolate up
  if (currNodeIndex != 0){
    PercolateUp(currNodeIndex);
  }
  // Incorporate something that gets us back to top
  //heap_index++; // So next one is put at the next index :)
  currNodeIndex++;
  heapIndexCounter++;
  //HeapArraySize++;
}

void MaxHeap::updateHeapNodeImpactVal(int index, double newImpactVal){
  TrishasHeapArray[index].impactVal = newImpactVal;
}

void MaxHeap::PercolateUp(int currNodeIndex){
  int parentNodeIndex = (currNodeIndex - 1)/2;
  int currNodeIndex_temp = currNodeIndex;
  while (TrishasHeapArray[parentNodeIndex].impactVal < TrishasHeapArray[currNodeIndex_temp].impactVal){
   //For Swap//                                                                                                                                                                      
   
   // sets current Node's impact and pointer back to BST in temp variables                                                                                                           
   int tempImpactVal = TrishasHeapArray[currNodeIndex_temp].impactVal;
   BST::BSTNode* temp = TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode;
   
   // swapping                                                                                                                                                                       
   TrishasHeapArray[currNodeIndex_temp].impactVal = TrishasHeapArray[parentNodeIndex].impactVal;
   TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode = TrishasHeapArray[parentNodeIndex].pointerToBSTNode;
   
   TrishasHeapArray[parentNodeIndex].impactVal = tempImpactVal;
   TrishasHeapArray[parentNodeIndex].pointerToBSTNode = temp;
	  
   // don't delete temp pointer because it was just temporarily taking ownership of BST pointer                                                                                      
   // delete temp;                                                                                                                                                                   

   // using pointer to trace back to BST where we update the index in the BSTNode                                                                                                    
   (* TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode).heapIndex = parentNodeIndex;
   (* TrishasHeapArray[parentNodeIndex].pointerToBSTNode).heapIndex = currNodeIndex_temp;
   // For Regular Percolate                                                                                                                                                          
   
   currNodeIndex_temp = parentNodeIndex;
   parentNodeIndex = (currNodeIndex_temp - 1)/2;
   
  }
}
//for reference
/*currNodeIndex = indexInVector;
  MaxHeap::HeapNode nodeHeapArray;
  nodeHeapArray.impactVal = passed_in_impact;
  //TrishasHeapArray[currNodeIndex].impactVal = passed_in_impact;
  nodeHeapArray.pointerToBSTNode = node;
  //TrishasHeapArray[currNodeIndex].pointerToBSTNode = node;

  TrishasHeapArray.push_back(nodeHeapArray);*/

BST::BSTNode * MaxHeap::RemoveFromHeap(int indexInVector){
  int parentNodeIndex = (indexInVector - 1)/2;
  int currNodeIndex_temp = indexInVector;
  while (currNodeIndex_temp > 0){

    //first, percolate current node to top of the heap:
    int tempImpactVal = TrishasHeapArray[currNodeIndex_temp].impactVal;

    BST::BSTNode* temp = TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode;                                                                                                                                                                  

    TrishasHeapArray[currNodeIndex_temp].impactVal = TrishasHeapArray[parentNodeIndex].impactVal;

    TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode = TrishasHeapArray[parentNodeIndex].pointerToBSTNode;

    TrishasHeapArray[parentNodeIndex].impactVal = tempImpactVal;

    TrishasHeapArray[parentNodeIndex].pointerToBSTNode = temp;

    // don't "delete temp" pointer because it was just temporarily taking ownership of BST pointer                                                                                      

    // delete temp;                                                                                                                                                                   

    // using pointer to trace back to BST where we update the index in the BSTNode                                                                                                    

    (* TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode).heapIndex = parentNodeIndex;

    (* TrishasHeapArray[parentNodeIndex].pointerToBSTNode).heapIndex = currNodeIndex_temp;

    currNodeIndex_temp = parentNodeIndex;

    parentNodeIndex = (currNodeIndex_temp - 1)/2;

  }

  //finished percolate up


  //currNodeIndex_temp = 0; //this is because currNodeIndex_temp is updated as a locally. By the end of percolate up, cNI SHOULD be 0. 

  //remove root and set last leaf node as root

  //now percolate down


  BST::BSTNode* pointerToReturn = TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode;

  (* TrishasHeapArray[0].pointerToBSTNode).heapIndex = -1;
  if (heapIndexCounter != 1){
    (* TrishasHeapArray[heapIndexCounter - 1].pointerToBSTNode).heapIndex = 0;
  }
  TrishasHeapArray[0].impactVal = TrishasHeapArray[heapIndexCounter - 1].impactVal;
  TrishasHeapArray[0].pointerToBSTNode = TrishasHeapArray[heapIndexCounter - 1].pointerToBSTNode;
  //(* TrishasHeapArray[0].pointerToBSTNode).heapIndex = 0;

  TrishasHeapArray.pop_back();

  int leftChildIndex = 2 * currNodeIndex_temp + 1;

  int rightChildIndex = 2 * currNodeIndex_temp + 2;

  //currNodeIndex_temp.impactVal orrrrr TrishasHeapArray[currNodeIndex_temp].impactVal

  while (TrishasHeapArray[currNodeIndex_temp].impactVal < TrishasHeapArray[leftChildIndex].impactVal || TrishasHeapArray[currNodeIndex_temp].impactVal < TrishasHeapArray[rightChildIndex].impactVal){

    int tempImpactVal = TrishasHeapArray[currNodeIndex_temp].impactVal;

    BST::BSTNode* temp = TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode;
    
    if (TrishasHeapArray[leftChildIndex].impactVal < TrishasHeapArray[rightChildIndex].impactVal){

      //right is larger, will swap with right

      TrishasHeapArray[currNodeIndex_temp].impactVal = TrishasHeapArray[rightChildIndex].impactVal;

      TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode = TrishasHeapArray[rightChildIndex].pointerToBSTNode;

      TrishasHeapArray[rightChildIndex].impactVal = tempImpactVal;

      TrishasHeapArray[rightChildIndex].pointerToBSTNode = temp;

      (* TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode).heapIndex = rightChildIndex;

      (* TrishasHeapArray[rightChildIndex].pointerToBSTNode).heapIndex = currNodeIndex;

    } else {

      // swap with left

      TrishasHeapArray[currNodeIndex_temp].impactVal = TrishasHeapArray[leftChildIndex].impactVal;

      TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode = TrishasHeapArray[leftChildIndex].pointerToBSTNode;

      TrishasHeapArray[leftChildIndex].impactVal = tempImpactVal;

      TrishasHeapArray[leftChildIndex].pointerToBSTNode = temp;

      (* TrishasHeapArray[currNodeIndex_temp].pointerToBSTNode).heapIndex = leftChildIndex;

      (* TrishasHeapArray[leftChildIndex].pointerToBSTNode).heapIndex = currNodeIndex;

    }

  }

  heapIndexCounter--;
  
  return pointerToReturn;

}


