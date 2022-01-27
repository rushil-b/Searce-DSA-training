//A program to check if 2 strings are anagram or not using Hash Table

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {

  char *A=new char[100]; //declared a 100 character strings A and B
  char *B=new char[100];
  std::cout << "Enter string A:" << '\n';
  std::cin >> A;

  std::cout << "Enter string B:" << '\n';
  std::cin >> B;

  int i,H[26]={0};

  for(i=0;A[i]!='\0';i++)
  {
    H[A[i]-97]++; //here A[i]-97 will give a simplified ASCII code to access the index
  }

  for(i=0;B[i]!='\0';i++)
  {
    H[B[i]-97]--;
    if(H[B[i]-97]<0) //to check 'not anagram' condition
    {
      std::cout << "A and B are not anagrams" << '\n';
      break;
    }
  }
  if(B[i]=='\0')
    std::cout << "A and B are anagrams" << '\n';

  return 0;
}
