//A program to detect loop in a LinkedList

#include <iostream>
using namespace std;

struct Node //created node structure for LinkedList
{
  int data;
  Node *next;
}*head=NULL;

void Display(Node *p) //Display function to display elements of the LinkedList
{
  while(p)
  {
    std::cout << p->data << ' ';
    p=p->next;
  }
}

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

int isLoop(Node *p) //to check if there's a loop in LinkedList or not
{
  Node *q,*r;
  q=r=p;

  do {
    q=q->next;
    r=r->next;
    if(r)
      r=r->next;
  } while(q && r && q!=r);

  if(q==r)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {//main function

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

  Node *t1,*t2; //Manually creating a loop in LinkedList to check if its working or not.
  t1=head->next->next;
  t2=head->next->next->next->next;
  t2->next=t1;

  if(isLoop(head)) //checking loop condition
    std::cout << "Yes there's a loop!" << '\n';
  else
    std::cout << "No loop" << '\n';

  return 0;
}
