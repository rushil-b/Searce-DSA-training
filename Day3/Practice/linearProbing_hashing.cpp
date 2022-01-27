//Programming one of the hashing techniques - Linear Probing

#include <iostream>
#define SIZE 10
using namespace std;

int hash1(int key) //function will take key and return index
{
  return key%SIZE;
}

int probe(int H[],int key) //function will linearly check and find next free space
{
  int index=hash1(key);
  int i=0;

  while(H[(index+i)%SIZE]!=0) i++;

  return (index+i)%SIZE;
}

void insert(int H[],int key)
{
  int index=hash1(key); //to get index of element 'key'

  if(H[index]!=0) //checking if that index is free or occupied
    index=probe(H,key);//find next free space
  H[index]=key;
}

int search(int H[],int key)
{
  int index=hash1(key); //getting index from hash table
  int i=0;

  while(H[(index+i)%SIZE]!=key) i++; //loop for linear probing

  return (index+i)%SIZE;
}

int main(int argc, char const *argv[]) {

  int HT[10]={0};

  int option; //menu driven option for user
  do {
    cout<<endl;
    std::cout << "Enter 1 to Insert an element in Hash" << '\n';
    std::cout << "Enter 2 to Search an element in Hash" << '\n';
    std::cout << "Enter 0 to close the program" << '\n';
    std::cin >> option;
    cout<<endl;
    switch (option) { //switch case to provide user-friendliness to the program
      case 1: std::cout << "Enter the element to insert" << '\n'; //case of enqueue
              int x;
              std::cin >> x;
              insert(HT,x);
      break;

      case 2: std::cout << "Enter a key to search" << '\n';
              int key;
              std::cin >> key;
              if(search(HT,key)<0) std::cout << "Key not found" << '\n';
              else std::cout <<'\n'<< "Key found at " << search(HT,key)<<'\n';
      break;

      default:  if(option!=0)
                  std::cout << "Enter value between 0 to 2!" << '\n';
    }
  } while(option!=0);

  return 0;
}
