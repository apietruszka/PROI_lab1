#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Numbers
{
  std::vector<int> v;

public:
  Numbers(std::vector<int> V);

  ~Numbers();


  void Print();

  Numbers* operator+(Numbers &b);

  Numbers* operator+=(Numbers &b);

  Numbers* operator*(Numbers &b);

  Numbers* operator*=(Numbers &b);

  int LowestDigitSum();

  int HighestNumber();
  bool Includes(int x);
};
