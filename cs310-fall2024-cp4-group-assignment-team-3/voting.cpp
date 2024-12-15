# include <iostream> 
# include <string>
# include <sstream>
# include "Trisha.h" //IDk if i need this or not?

using namespace std;

int main() {
  Trisha * theTrisha = new Trisha();
  
  cout << "The election cycle has begun! \nBetter bring voters to the polls\n";
  while(1){
    string input;
    getline(cin, input);
    stringstream inputData(input);
    string component;
    vector<string> vectorizedInput;
    while(inputData >> component){ //takes one value out of the stream and puts it into component by white space
      vectorizedInput.push_back(component);
    }
    
    // PROCESS COMMANDS //
    
    // for voter
    if (vectorizedInput.at(0) == "voter"){
      if(vectorizedInput.size()==4){
	// call voter(firstName, lastName, age)
	// we swapped around first and last name...dont want to fix it in the other files, that is why the order is weird here
	theTrisha->voter(vectorizedInput.at(2), vectorizedInput.at(1), stoi(vectorizedInput.at(3)));
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the voter command...what are you up to...?";
      }
    }
    
    // for voted
    if(vectorizedInput.at(0) == "voted"){
      if(vectorizedInput.size()==4){
	// call voter(firstName, lastName, age)
	// we swapped around first and last name...dont want to fix it in the other files, that is why the order is weird here
	theTrisha->voted(vectorizedInput.at(2), vectorizedInput.at(1), stoi(vectorizedInput.at(3)));
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the command voted...what are you up to...?";
      }
    }
    
    // for support 
    if(vectorizedInput.at(0) == "support"){
      if(vectorizedInput.size()==4){
	// call voted(firstName, lastName, age)
	// we swapped around first and last name...dont want to fix it in the other files, that is why the order is weird here
	theTrisha->support(vectorizedInput.at(2), vectorizedInput.at(1), stoi(vectorizedInput.at(3)));
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the command support...what are you up to...?";
      }
    }
    
    // for reduce likelihood 
    if(vectorizedInput.at(0) == "reduce-likelihood"){
      if(vectorizedInput.size()==4){
	// call reduce_likelihood(firstName, lastName, likelihoodVal)
	// we swapped around first and last name...dont want to fix it in the other files, that is why the order is weird here
	theTrisha->reduce_likelihood(vectorizedInput.at(2), vectorizedInput.at(1), stod(vectorizedInput.at(3)));
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the command reduce likelihood...what are you up to...?";
      }
    }
    
    // for chauffer
    if(vectorizedInput.at(0) == "chauffeur"){
      if(vectorizedInput.size()==1){
	// call chauffeur()
	      theTrisha->chauffeur();
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the command chauffeur...what are you up to...?";
      }
    }
    
    // for show impact
    if(vectorizedInput.at(0) == "show-impact"){
      if(vectorizedInput.size()==1){
	// call show_impact()
	theTrisha->show_impact();
      }
      else{
	cout << "Election Fraud Detected!!!! You have entered an unacceptable amount of parameters for the command show impact...what are you up to...?";
      }
    }
    // for quit
    if (vectorizedInput.at(0)=="quit"){
      cout << "POLLING COMPLETE! \n Trisha recieved XX votes, our chauffeur did a great job! \n but Trisha lost the election.";
      break;
    }
    
  }
  return(1);
}
