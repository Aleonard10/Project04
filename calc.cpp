#include <iostream>
#include "dstack.h"
#include <cmath>
#include <cctype>

using namespace std;


int main()
{
    dstack stack;
    double value;
    double newValue;
    char Operator;

    char peekChar = cin.peek();

    while (peekChar != EOF)
    {
        if (isspace(peekChar))
        {
            cin.ignore();
        }
        else if (isdigit(peekChar))
        {
            cin >> value;
            stack.push(value);
            stack.setSize(1);
        }
        else if (ispunct(peekChar))
        {
            cin >> Operator;
            double first;
            double second;
            // if statements used to check if the stack is empty before removing the top value
            if (stack.empty() || stack.size() < 2)
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            stack.pop(first);
            stack.setSize(0);
            if (stack.empty())
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            stack.pop(second);
            stack.setSize(0);

            if (Operator == '+')
            {
                newValue = first + second;
                stack.push(newValue);
                stack.setSize(1);
            }
            else if (Operator == '-')
            {
                newValue = second - first;
                stack.push(newValue);
                stack.setSize(1);
            }
            else if (Operator == '/')
            {
                if (second == 0)
                {
                    exit(1);
                }
                newValue = second / first;
                stack.push(newValue);
                stack.setSize(1);
            }
            else if (Operator == '*')
            {
                newValue = first * second;
                stack.push(newValue);
                stack.setSize(1);
            }
            else if (Operator == '^')
            {
                newValue = pow(second, first);
                stack.push(newValue);
                stack.setSize(1);
            }

        }
        else
        {
            cout << "No condition satisfied." << endl;
            exit(1);
        }
        peekChar = cin.peek();
    }
    stack.pop(newValue);
    stack.setSize(0);
    cout << newValue << endl;

    return 0;
}
