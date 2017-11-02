#include <iostream>
#include <stdlib.h>
#include <vector>
#include <climits>
#include "Numbers.h"



using namespace std;

void printMenu()
{
	cout<<"1. Add new Numbers object"<<endl;
	cout<<"2. Print all Numbers"<<endl;
	cout<<"3. Create a new object (+)"<<endl;
	cout<<"4. Modify object (+=)"<<endl;
	cout<<"5. Create a new object (*)"<<endl;
	cout<<"6. Modify object (*=)"<<endl;
	cout<<"7. Print Highest Number"<<endl;
	cout<<"8. Print Lowest Digit Sum"<<endl;
	cout<<"9. Exit"<<endl;
}

Numbers* newNumbersInteractive()
{
	int buff;
	std::vector<int> vec;
	
	
	
	while(true)
	{
		cout<<"1. Add a new Number"<<endl<<"2. Finish adding this object"<<endl;
		do
		{
            while(!(cin>>buff))
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wrong data type!"<<endl;
            }
		}while(buff!=1&&buff!=2);
		if(buff==1)
		{
			int num;
			do
			{
				cout<<"Give me number from 1000 to 9999: "<<endl;
                while(!(cin>>num))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(num<1000||num>9999);
			vec.push_back(num);
		}
		if(buff==2)
		{
			Numbers *toRet = new Numbers(vec);
			return toRet;
		}
	}
}

void printAll(std::vector<Numbers*>allNums)
{
	for(int i=0;i<allNums.size();i++)
			{
				cout<<i<<". ";
                (*allNums[i]).Print();
			}
}


int main()
{
  std::vector<Numbers*>allNums;


	int x, y;
	int buf;
	
	cout<<"1. Manual test"<<endl;
	cout<<"2. Automatic test"<<endl;
    while(!(cin>>buf))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Wrong data type!"<<endl;
    }
	
	if(buf==1)
	{
	while(true)
	{

		do
		{
			printMenu();
			while(!(cin>>buf))
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Wrong data type!"<<endl;
            }
		}while(buf<1&&buf>9);

		switch(buf)
		{
			case 1:
			allNums.push_back(newNumbersInteractive());
			break;
			case 2:
			printAll(allNums);
			break;
			case 3:
			printAll(allNums);
                if(allNums.size()<2)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			do
			{
				cout<<"give me 2 indicies as operator arguments."<<endl;

                while(!(cin>>x>>y))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||y<0||x>allNums.size()||y>allNums.size());
			
			allNums.push_back(*allNums[x]+(*allNums[y]));
			break;
			
			case 4:
			printAll(allNums);
                if(allNums.size()<2)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			do
			{
				cout<<"give me 2 indicies as operator arguments."<<endl;
                while(!(cin>>x>>y))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||y<0||x>allNums.size()||y>allNums.size());
                *allNums[x]+=(*allNums[y]);
			break;
			
			case 5:
			printAll(allNums);
                if(allNums.size()<2)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			
			do
			{
				cout<<"give me 2 indicies as operator arguments."<<endl;
                while(!(cin>>x>>y))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||y<0||x>allNums.size()||y>allNums.size());
			allNums.push_back(*allNums[x]*(*allNums[y]));
			break;
			
			case 6:
			printAll(allNums);
                if(allNums.size()<2)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			do
			{
				cout<<"give me 2 indicies as operator arguments."<<endl;
                while(!(cin>>x>>y))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||y<0||x>allNums.size()||y>allNums.size());
                *allNums[x]*=(*allNums[y]);
			break;
			
			case 7:
			printAll(allNums);
			if(allNums.size()<1)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			do
			{
				cout<<"give me index as argument."<<endl;
                while(!(cin>>x))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||x>allNums.size());
			cout<<(*allNums[x]).HighestNumber()<<endl;
			break;
			case 8:
			printAll(allNums);
			if(allNums.size()<1)
                {
                    cout<<"not enough numbers to use operator."<<endl;
                    break;
                }
			do
			{
				cout<<"give me index as argument."<<endl;
                while(!(cin>>x))
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Wrong data type!"<<endl;
                }
			}while(x<0||x>allNums.size());
			cout<<(*allNums[x]).LowestDigitSum()<<endl;
			break;
			case 9:
			return 0;
		}
	}
	}

else if(buf==2)
{
  cout<<"Testing adding objects:"<<endl;
  std::vector<int> v1;
  v1.push_back(1342);
  v1.push_back(2234);
  v1.push_back(1111);
  v1.push_back(1239);
  
  std::vector<int> v2;
  v2.push_back(2999);
  v2.push_back(1111);
  
  
  Numbers n1(v1);
  Numbers n2(v2);

	cout<<"Testing operators: "<<endl;

cout<<"testing + operator: "<<endl;
 Numbers n3=(*(n1+n2));
 n3.Print();
 
  cout<<"testing *= operator: "<<endl;
  n1 *= n2;
  n1.Print();
  
  cout<<"testing ++ operator: "<<endl;
  n1+=n3;
  n1.Print();
  
  cout<<"testing * operator: "<<endl;
  n1=*(n1*n3);
  n1.Print();
  
  cout<<"testing printing: "<<endl;
  n1.Print();

    cout<<"testing highest number:"<<endl;
  cout << n1.HighestNumber() << endl;
  
  cout<<"testing lowest digit sum:"<<endl;
  cout << n1.LowestDigitSum() << endl;
}

  return 0;
}
