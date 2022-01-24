//Program to insert an element in a Sorted Array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void InsertSort(int *A,int n,int x) //function to insert in sorted array
{
  int i=n-1;
  while(i>=0 && A[i]>x)
  {
    A[i+1]=A[i];
    i--;
  }
  A[i+1]=x;
}

int main(int argc, char const *argv[]) {//main function

  int sz,*A;
  std::cout << "Enter array size:" << '\n';
  std::cin >> sz;

  if(sz<0) //checking validity of size of array entered
  {
    std::cout << "Invalid entry of size of array" << '\n';
    return 0;
  }

  A=new int[sz+1];

  std::cout << "Enter "<<sz<<" elements:" << '\n';
  for (size_t i = 0; i < sz; i++) {
    std::cin >> A[i];
  }
  A[sz]=INT_MAX; //assuming the array is ascending order sorted.

  int x;
  std::cout << "Enter an element to insert:" << '\n';
  std::cin >> x;

  InsertSort(A,sz+1,x); //function call to insert element x in sorted array A

  std::cout << "New array:" << '\n';
  for(int i=0;i<sz+1;i++) //displaying the new array
  {
    std::cout << A[i] << ' ';
  }

  return 0;
}
