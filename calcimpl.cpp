// Robert Bennethum
//
// Program to turn to postfix and calculate values
//
//

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

using namespace std;

bool Operand(char c);
int Precedence(char c);

string InfixToPostfix(string infix)
{
    string postfix;
    Stack<char> s;
    for (size_t i = 0; i < infix.length(); i++)
    {
        if (Operand(infix[i]))
        {
            postfix += infix[i]; //sends value to output if digit
        }
        else
        {
            switch (infix[i])
            {
                case '(':
                    s.Push(infix[i]); //pushes value onto stack if (
                    break;

                case '*':
                case '/':
                case '+':
                case '-':
                    while (!s.IsEmpty() && Precedence(infix[i]) <= Precedence(s.Top()))
                        postfix += s.Pop(); //pops the value and sends to output
                    s.Push(infix[i]); //pushes the operator onto stack
                    break;

                case ')':
                    while (s.Top() != '(')
                        postfix += s.Pop();
                    s.Pop(); //pops and outputs top of stack until reaches (
                    break;

                case ';':
                    while (!s.IsEmpty())
                        postfix += s.Pop(); //pops and outputs top of stack
                    postfix += ';';
                    break;
            }
        }
    }
    return postfix; //returns the output
}

double EvaluatePostfix(string postfix)
{
    Stack<double> st;
    for (int i = 0; i < postfix.length()-1; i++)
    {
        if (Operand(postfix[i])) //if value is digit push onto stack
            st.Push(postfix[i]-'0'); //subtracts '0' to put into normal decimal
        else
        {
            double operand1 = st.Pop(); //pops top two values and assigns to variables
            double operand2 = st.Pop();
            switch (postfix[i]) //if value is operator, use that operator
            {
                case '+':
                    st.Push(operand2 + operand1);
                    break;
                case '-':
                    st.Push(operand2 - operand1);
                    break;
                case '*':
                    st.Push(operand2 * operand1);
                    break;
                case '/':
                    st.Push(operand2 / operand1);
                    break;
            }
        }
    }
    return st.Pop();
}
bool Operand(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}
int Precedence(char c)
{
    if (c == '(' || c == ')')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return -1;
}
