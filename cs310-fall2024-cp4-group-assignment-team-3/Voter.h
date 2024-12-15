#ifndef _H_Voter_
#define _H_Voter_

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Voter {
public:
  string firstName;
  string lastName;
  unsigned int age;
  unsigned int strengthVal;
  double likelihoodVal;
  double impactVal;
  
  //auto operator<=>(const Voter &other) const = default;

  Voter();
  Voter(string firstName, string lastName, unsigned int newAge);
  
  //void show();

  //friend ostream &operator<<(ostream &out, Voter &voter);

  //bool operator<(const Voter &other);
  //bool operator==(const Voter &other);
};

#endif
