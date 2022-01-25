//Polynomial Representation using LinkedList

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node //polynomial node consisting of coefficient, exponent and next pointer node.
{
  int coeff;
  int exp;
  Node *next;
}*poly=NULL;

void create()
{
  Node *t,*last=NULL;
  int num,i;

  std::cout << "Enter number of terms of the polynomial" << '\n';
  std::cin >> num;

  std::cout << "Enter each term one by one with coefficient and exponent - " << '\n';

  for(i=0;i<num;i++)
  {
    t=new Node;
    std::cin >> t->coeff>>t->exp;
    t->next=NULL;
    if(poly==NULL)
    {
      poly=last=t;
    }
    else
    {
      last->next=t;
      last=t;
    }
  }
}

void Display(Node *p) //Display function to display elements of the LinkedList
{
  while(p)
  {
    std::cout << p->coeff << "x^"<<p->exp<<" +";
    p=p->next;
  }
  cout<<endl;
}

long eval(Node *p,int x)
{
  long val=0;

  while(p)
  {
    val+=p->coeff*pow(x,p->exp);
    p=p->next;
  }
  return val;
}

int main(int argc, char const *argv[]) {

  create();
  cout<<endl;
  std::cout << "Polynomial entered-" << '\n';
  Display(poly);

  int x;
  std::cout << "Enter value of x" << '\n';
  std::cin >> x;
  std::cout << '\n'<<"Evaluating the polynomial we get answer = " << eval(poly,x)<<'\n';

  return 0;
}
