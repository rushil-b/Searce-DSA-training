//Coding Queue using LinkedList

#include <iostream>
using namespace std;

struct Node  //declared Node structure
  {
     int data;
     Node *next;
  }*front=NULL,*rear=NULL;

void enqueue(int x) //function to insert an element in queue
  {
     Node *t;
     t=new Node;

     if(t==NULL)
      std::cout << "Queue is full" << '\n';
     else
     {
       t->data=x;
       t->next=NULL;

       if(front==NULL)
        front=rear=t;
       else
       {
         rear->next=t;
         rear=t;
       }
     }

  }

int dequeue() //function to delete the element in the queue
  {
     int x=-1;
     Node* t;

     if(front==NULL)
      std::cout << "Queue is empty" << '\n';
     else
     {
       x=front->data;
       t=front;
       front=front->next;
       delete t;
     }
     return x;
  }

void Display() //function to display the queue
  {
     Node *p=front;
     while(p)
     {
       std::cout << p->data << ' ';
       p=p->next;
     }
     cout<<endl;
  }

int main() //main function
{

  int option; //menu driven option for user
  do {
    cout<<endl;
    std::cout << "Enter 1 for ENQUEUE an element" << '\n';
    std::cout << "Enter 2 for DEQUEUE an element" << '\n';
    std::cout << "Enter 3 to DISPLAY the Queue" << '\n';
    std::cout << "Enter 0 to close the program" << '\n';
    std::cin >> option;
    cout<<endl;
    switch (option) { //switch case to provide user-friendliness to the program
      case 1: std::cout << "Enter the element to enqueue" << '\n'; //case of enqueue
              int x;
              std::cin >> x;
              enqueue(x);
      break;

      case 2: int del; //case of dequeue
              del=dequeue();
              if(del!=-1)
                std::cout << del<<" Dequeued!" << '\n';
      break;

      case 3: Display(); //case of displaying the queue;
      break;

      default:  if(option!=0)
                  std::cout << "Enter value between 0 to 3!" << '\n';
    }
  } while(option!=0);

 return 0;
}
