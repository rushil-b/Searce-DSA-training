//A program to reverse an array
//Name - Rushil Bangia

#include <iostream>
using namespace std;

void swap(int *x, int *y) //function to swap the elements
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

int * reverseArray(int * Arr,int n)  //function to reverse the array
{
  int start=0, end=n-1;
  while(start<end)    //swapping technique of start and end elements of an array
  {
    swap(&Arr[start],&Arr[end]);
    start++;
    end--;
  }
  return Arr;
}

void Display(int * Arr,int n) //function to display the array
{
  if(n==0)
    std::cout << "No elements in the array" << '\n';
  else
  {
    for(int i=0;i<n;i++)
    {
      std::cout << Arr[i] << ' ';
    }
  }
}

int main(int argc, char const *argv[]) { //main function

  int Q,*P,*res;
  std::cout << "Enter size of array" << '\n';
  std::cin >> Q; //enter size of array and store in variable Q

  if(Q<0)  //condition to check Invalid size
  {
    std::cout << "Invalid size entered" << '\n';
    return 0;
  }

  P= new int[Q]; //dynamic array P created of size Q

  std::cout << "Enter " <<Q<<" elements:"<< '\n';
  if(Q==0)
    std::cout << "No elements in the array" << '\n';
  else
  {
    for(int i=0;i<Q;i++) //inserting elements in the array P
    {
      std::cin >> P[i];
    }
  }

  res=reverseArray(P,Q); //function to reverse the array elements

  std::cout << "Reversed array:" << '\n';
  Display(res,Q); //function to display the array

  return 0;
}
