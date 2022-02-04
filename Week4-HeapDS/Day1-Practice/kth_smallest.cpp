//Program to find Kth smallest element using Heap

#include <iostream>
#include <queue> //for using heap functions
using namespace std;

void kSmallest(int *A,int size,int k)
{
  priority_queue<int> maxH; //declaring a max heap 'maxH'

  for(int i=0;i<size;i++)
  {
    maxH.push(A[i]);    //pushing elements of array in heap
    if(maxH.size()>k)   //condition when size of heap exceeds k
    {
      maxH.pop();
    }
  }

  std::cout << k <<"(rd)/(th) smallest element is: "<<maxH.top()<< '\n'; //the top element of the heap will be the kth smallest element
}

int main(int argc, char const *argv[]) {//main function

  int size,*A;
  std::cout << "Enter array size" << '\n';
  std::cin >> size;

  A=new int[size];

  std::cout << "Enter "<<size<<" elements" << '\n';

  for(int i=0;i<size;i++)
  {
    std::cin >>A[i];
  }

  int k;
  std::cout << "Enter k" << '\n';
  std::cin >> k;

  kSmallest(A,size,k); //function call to compute kth smallest element

  return 0;
}
