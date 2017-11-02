#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Numbers.h"
using namespace std;

Numbers::Numbers(std::vector<int> V)
{
  for(int i=0;i<V.size();i++)
  {
    if (V[i]<1000 || V[i]>9999)
    {
      cout << "Constructor error. Number in wrong range" << endl;
    }
  }

  cout<<"Creating Numbers object: ";
  Numbers::v=std::vector<int>();
  Numbers::v=V;
  Print();
}

  Numbers::~Numbers()
  {
    cout<<"Destroying Numbers object: ";
    Print();
  }


  void Numbers::Print()
  {
    for(int i=0;i<Numbers::v.size();i++)
      cout<<Numbers::v[i]<<" ";
    cout<<endl;
  }

  Numbers* Numbers::operator+(Numbers &b)
  {
	  //new element involving every element from this and b, with no repetitions
    std::vector<int> vec;

    for(int i=0; i<b.v.size();i++)
      vec.push_back(b.v[i]);

    for(int i=0; i<Numbers::v.size(); i++)
      if(!b.Includes(v[i]))
        vec.push_back(v[i]);

    Numbers* ret = new Numbers(vec);
    return ret;
  }

  Numbers* Numbers::operator+=(Numbers &b)
  {
      Numbers *buf = (*this)+b;
      *this=*(buf);
      delete buf;
      return this;
  }

  Numbers* Numbers::operator*(Numbers &b)
  {
	  //new element with every element from this that is also in b
    std::vector<int> vec;

    for(int i=0; i<Numbers::v.size(); i++)
      if(b.Includes(Numbers::v[i]))
        vec.push_back(Numbers::v[i]);

      Numbers* ret = new Numbers(vec);
    return ret;
  }

  Numbers* Numbers::operator*=(Numbers &b)
  {
      Numbers *buf = (*this)*b;
      *this=*(buf);
      delete buf;
      return this;
  }

  int Numbers::LowestDigitSum()
  {
    int sum=37;
    int toRet=0;
    int buf, num;
    for (int i=0; i<v.size(); i++)
    {
      num = v[i];
      buf = (num % 10) + ((num % 100)/10) + ((num % 1000)/100) + ((num)/1000);
      if (buf < sum)
      {
        sum = buf;
        toRet = num;
      }
    }

    return toRet;
  }

  int Numbers::HighestNumber()
  {
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
      if (Numbers::v[i] > max)
        max = Numbers::v[i];
    }
    return max;
  }

  bool Numbers::Includes(int x)
  {
    for (int i = 0; i < Numbers::v.size(); i++)
    {
      if(Numbers::v[i]==x)
        return true;
    }
    return false;
  }
