//A program for searching a key in the sorted array using Binary Search.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *A,int n,int key)
{
  int low=0,high=n-1;
  int mid;

  while(low<=high)
  {
    mid=(low+high)/2;
    if(key==A[mid])
      return mid;
    else if(key<A[mid])
      high=mid-1;
    else
      low=mid+1;
  }
  return -1;
}

int main(int argc, char const *argv[]) {

  int sz,key,*A;
  std::cout << "Enter array size:" << '\n';
  std::cin >> sz;

  if(sz<0) //checking validity of size of array entered
  {
    std::cout << "Invalid entry of size of array" << '\n';
    return 0;
  }

  A=new int[sz];

  std::cout << "Enter "<<sz<<" elements in ascending order only:" << '\n';
  for (size_t i = 0; i < sz; i++) {
    std::cin >> A[i];
  }

  std::cout << "Enter a key to search" << '\n';
  std::cin >> key;

  int res=BinarySearch(A,sz,key);
  if(res==-1)
    std::cout << "Key not found" << '\n';
  else
    std::cout << "Key found at position : " <<res<< '\n';

  return 0;
}
