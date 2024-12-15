The purpose of this project was to build a system that encourages citizens to go out and vote! The code supports a Voter class, which has data members: first name, last name, and age. Our voters are stored in a Binary Search Tree, and the BST is sorted by each voter's first name, and then last name (no two voters have the exact same name). Additionally, each node in the BST points to a node in a Max Heap, which is implemented as a Max Heap Array. The Max Heap stores voters by their  "Impact Value", or how likely they are to vote for our candidate of choice (Trisha Paytas, a popular influencer). To display all of the voters at once, a vector was made. Each index in the vector acts as the head of a linked list of voters with the same age (think of this as a hash table with chaining and direct indexing). Each data structure is accompanied by a header and source file, the former containing the construction of each data structure, and the latter containing helper function to aid in their implementation. Below is a description of what each function in the main file, Trisha.cpp, does. These explainations are condensed are reworded versions, taken from the assignment description provided by the professor:

voter <last-name> <first-name> <age>
Adds a new voter to the system. Last name and first name have no spaces or special characters, just letters. Age is an integer; you should make sure it is between 18 and 118, and if not, this voter "registration" withe system should be rejected. Your program should also reject a voter with the same first name, last name, and age, as a voter already in the system. Purple text is typed by the user, green text is output produced by your program.



voted <last-name> <first-name> <age>
Simulates a volunteer contacting a voter, and the voter letting us know that they have already voted. These voters should be removed from consideration for a limo ride to the polls.



quit
Program halts.



support <last-name> <first-name> <strength>
Simulates contacting the voter named Mike Lewis, and hearing that their strength of support has increased by 20 points. Don't worry about how our volunteers determine that this is the case; they are highly trained! The initial strength of support of each voter should be set at 75.  You may assume that <strength> will be entered as a positive integer. That is, a voter's strength of support can only increase throughout the day. The purpose of keeping track of strength of support is to help determine which voter to drive to the polls next.



reduce-likelihood <last-name> <first-name> <reduction>
This operation simulates contact from a volunteer who assesses that the likelihood of this voter actually getting to the polls and voting has gone down by 10%.  Initially all voters' likelihood should be set at 75%, and if this were the first invocation of likelihood, your program should change that value, for this voter, as follows:
likelihood = likelihood * (100 - reduction)
By maintaining each voter's strength of support, and likelihood of voting, we can compute the impact of driving them to the polls as follows:
impact = strength / likelihood
So the following operation (which takes no parameters) should simulate driving one voter to the polls; that voter should be the one with maximum potential to add another vote to our candidate's total (that is, the voter whose "impact" is currently highest):



chauffeur 
Brings a voter to the polls because their likelihood was the greatest of all the voters.



show-impact
This command should show all voters, ordered by age, along with their strength of support, likelihood, and calculated impact values, as follows:



Efficiency Requirements
support and reduce-likelihood must work in O(log N) time where N is the number of voters
chauffeur must work in O(log N) time
voted and voter must work in O(log N) time
show-impact should work in O(N) time
