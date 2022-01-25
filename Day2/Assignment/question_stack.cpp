//This program uses stack and strings to implement.
//A program to solve three types of queries and display the type 3 query with the maximum element in stack.

//Name-Rushil Bangia

#include <iostream>
#include <string.h>
#include <sstream>
#include <bits/stdc++.h>
#include <stack> //using STL
using namespace std;

int * getMax(string operations[],int n) //This function returns the Maximum element display array for type 3 query and performs operations for type 1 and 2 query.
{
  stack<int> st; //ordinary stack
  stack<int> max; //another stack to track maximum element in stack st
  max.push(0); //initialised with lowest value in 'max' stack

  int *A=new int[n]; //allocated array space which will later be returned as result from this function
  memset(A,0,sizeof(A)); //initialised all elements to be zero of A
  int c=0; //counter for position of last element in 'n' sized array.
  for(int i=0;i<n;i++)
  {
    if(operations[i][0]=='1') //type1 query condition
    {
      string r=operations[i].substr(2); //extract the value 'x'
      if(r=="")
        std::cout << "'x' is missing! Enter a value also along with query - 1 to push into stack! " << '\n';
      else
      {
        stringstream no_fetch(r); //to convert substring to integer
        int x=0;
        no_fetch >> x;
        if(x>=max.top()) //check if the entered element is greater than already max element in stack
          max.push(x);
        st.push(x);
      }
    }
    else if(operations[i][0]=='2') //type 2 query
    {
      if(st.empty())
        std::cout << "Stack is empty. Unable to pop an element" << '\n';
      else
      {
        if(st.top()==max.top()) max.pop(); //pop max element if its same as that of original stack top
        st.pop();
      }
    }
    else if(operations[i][0]=='3') //type3 query
    {
      if(!st.empty())
      {
        A[c++]=max.top(); //storing maximum element
      }
    }
    else
    {
      std::cout << "Query number "<< i+1 << " is not valid. Its not between the range from 1 to 3. Change it!"<<'\n';
    }
  }
  A[c]=0; //marker for end of array A
  return A;
}

int main(int argc, char const *argv[]) {

  int q;

  std::cout << "In this program, you have to write queries. They are of following type -" << '\n';
  std::cout << "1 x - Push the element 'x' into the stack" << '\n';
  std::cout << "2   - Delete the element present at the top of the stack." << '\n';
  std::cout << "3   - Print the maximum element in the stack." << '\n';
  cout<<endl;
  std::cout << "Enter the number of operations/queries to perform : " << '\n';
  std::cin >> q;

  string operations[q]; //string of operations to be entered by user

  cout<<endl;
  std::cout << "Enter "<<q<<" query types : " << '\n';
  cin >> ws;
  for(int i=0;i<q;i++)
  {
    getline(cin, operations[i]); //input all query types
  }

  int *res=new int[q];
  res=getMax(operations,q);

  cout<<endl;
  std::cout << "Output - " << '\n';
  for(int i=0;res[i]!=0;i++) //display the maximum elements according to type 3 queries entered by user
  {
    std::cout << res[i] << '\n';
  }

  return 0;
}
