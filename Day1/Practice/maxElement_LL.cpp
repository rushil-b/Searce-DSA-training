//A program to display sum of nodes' data in a LinkedList

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
}*head=NULL;

void createLL(int A[], int n) //function to create LinkedList
{
    int i;
    struct Node *t,*last; //a temporary Node pointer and last Node pointer taken
    head=new Node;
    head->data=A[0]; //initialising head node
    head->next=NULL;
    last=head;

    for(i=1;i<n;i++) //creating other nodes
    {
      t=new Node;
      t->data=A[i];
      t->next=NULL;
      last->next=t;
      last=t;
    }
}

int Max(Node *p) //function to find maximum element in the LinkedList
{
  int max=INT_MIN;

  while(p)
  {
    if(p->data>max)  //condition for maximum element
      max=p->data;

    p=p->next;
  }
  return max;
}

int main(int argc, char const *argv[]) { //main function

  int p,*A;
  std::cout << "Enter number of nodes in the Linked List:" << '\n';
  std::cin >> p;

  if(p<0) //checking valid LinkedList or not
  {
    std::cout << "Invalid entry of number of nodes" << '\n';
    return 0;
  }
  if(p==0) //checking for 0 node condition
  {
    std::cout << "No nodes to display" << '\n';
    return 0;
  }

  A=new int[p]; //creating array to store the elements of LinkedList

  std::cout << "Enter " <<p<<" elements:"<< '\n';
  for(int i=0;i<p;i++)
  {
    std::cin >> A[i]; //storing data in the array
  }
  std::cout << '\n';

  createLL(A,p); //function call to create LinkedList

  std::cout << "Displaying maximum element in the linked list= " <<Max(head)<< '\n';
   //function call to display the maximum element in LinkedList

  return 0;
}
