// A program to find out if the paranthesis("()") is matching in an expression.
// this program doesn't check if the paranthesis are proper in the expression. It only checks whether the number of paranthesis are matching or not.

#include <iostream>
#include <stack> //using STL
using namespace std;

int isBalanced(string exp) //function to check if paranthesis are matching or not
{
  stack<char> st; //created a stack- st
  int i;
  for(i=0;exp[i]!='\0';i++) //loop going through whole of expression
  {
    if(exp[i]=='(')          //if character is an opening bracket push it in stack
      st.push(exp[i]);
    else if(exp[i]==')')    //closing bracket when encountered, pop the element from stack
    {
      if(st.empty()) //checking condition of empty stack
        return 0;
      st.pop();
    }
  }
  if(st.empty()) //in the end if stack is empty, paranthesis are matching
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {

  string exp; //declared an expression in form of string

  std::cout << "Enter an expression" << '\n';
  std::cin >> exp;
  std::cout << '\n';

  if(isBalanced(exp)) //called the expression to check if paranthesis are balanced
    std::cout << "Paranthesis are matching" << '\n';
  else
    std::cout << "Paranthesis are not matching" << '\n';

  return 0;
}
