#include "Voter.h"

Voter::Voter(){
  firstName = "";
  lastName = "";
  age = 0;
  strengthVal = 75;
  likelihoodVal = 75;
  impactVal = strengthVal/likelihoodVal;
}

Voter::Voter(string first, string last, unsigned int newAge) {
	firstName = first;
	lastName = last;
	age = newAge;
	strengthVal = 75;
	likelihoodVal = 75;
	impactVal = strengthVal/likelihoodVal;
}

//Voter::Voter(
