//A menu driven program which implements Circular Queue

#include <iostream>
using namespace std;

struct Queue //structure Queue declared
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(Queue *q,int size) //function to allocate Queue memory and declare its variables.
{
  q->size=size;
  q->front=q->rear=0;
  q->Q=new int[q->size];
}

void enqueue(Queue *q,int x) //function to insert an element in Queue
{
  if((q->rear+1)%(q->size)==q->front)   //MOD function gives circularity to the queue.
    std::cout << "Queue is full" << '\n';
  else
  {
    q->rear=(q->rear+1)%(q->size);
    q->Q[q->rear]=x;                //pushing rear forward circularly and inserting an element there.
    std::cout << x <<" Enqueued!" << '\n';
  }
}

int dequeue(Queue *q) //function to delete the element from queue.
{
  int x=-1;
  if(q->front==q->rear)  //queue empty condition
    std::cout << "Queue is empty" << '\n';
  else
  {
    q->front=(q->front+1)%(q->size); //push front forward circularly and fetch the deleted element
    x=q->Q[q->front];
  }
  return x;
}

void Display(Queue q) //method to display the queue
{
  int i=(q.front+1)%(q.size);

  if(q.front==q.rear) //queue empty condition
    std::cout << "Nothing to display. Queue is empty." << '\n';
  else
  {
    do {
      std::cout << q.Q[i] << ' ';
      i=(i+1)%q.size;
    } while(i!=(q.rear+1)%q.size);
  }

  cout<<endl;
}

int main(int argc, char const *argv[]) {//main function

  struct Queue q; int sz;
  std::cout << "Enter size of the Circular Queue:" << '\n';
  std::cin >> sz;

  create(&q,sz); //calling create function to allocate Queue

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
              enqueue(&q,x);
      break;

      case 2: int del; //case of dequeue
              del=dequeue(&q);
              if(del!=-1)
                std::cout << del<<" Dequeued!" << '\n';
      break;

      case 3: Display(q); //case of displaying the queue;
      break;

      default:  if(option!=0)
                  std::cout << "Enter value between 0 to 3!" << '\n';
    }
  } while(option!=0);

  return 0;
}
