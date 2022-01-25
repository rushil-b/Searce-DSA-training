//Infix to Postfix conversion code

#include <iostream>
#include <cstring>
#include <stack> //using STL
using namespace std;
stack<char> st;

int pre(char x) //checking the precidences
{
  if(x=='+'||x=='-')
    return 1;
  else if(x=='*'||x=='/')
    return 2;
  return 0;
}

int isOperand(char x)//check if symbol is operator or operand
{
  if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
  return 1;
}

char * IntoPost(char *infix) //function to convert infix to postfix
{
    int i=0,j=0;
    char *postfix;
    long len=strlen(infix);
    postfix=new char[len+2];

    while(infix[i]!='\0')
    {
      if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
      else
      {
        if(pre(infix[i])>pre(st.top()))
          st.push(infix[i++]);
        else
          {
            postfix[j++]=st.top();
            st.pop();
          }
      }
    }

    while(!st.empty())
    {
      postfix[j++]=st.top();
      st.pop();
    }
    postfix[j-1]='\0';

    return postfix;
}

int main(int argc, char const *argv[]) {

  char *infix=new char[1000];
  std::cout << "Enter a simple infix expression" << '\n';
  std::cin >> infix;

  st.push('#');

  char *postfix=IntoPost(infix);

  std::cout << "Postfix expression=" <<postfix<< '\n';
  return 0;
}
