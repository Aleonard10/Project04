#include <iostream>
#include "dstack.h"
#include <cmath>
using namespace std;

int main()
{
    dstack stack;
    //int stackSize = 0;
    double value;
    double newValue;
    const int MAX = 200;
    int operatorCount = 0;
    char Operator[MAX];
    int size = 0;



    while(cin >> value)
    {
        if (cin.peek() == ' ')
        {
            cin.ignore();
            stack.push(value);
            size++;

        }
        else if(cin.peek() == '+' || cin.peek() == '-' ||cin.peek() == '/' || cin.peek() == '*' || cin.peek() == '^')
        {
            stack.push(value);
            size++;
            //read the operator pop 2 off stack
            cin >> Operator[operatorCount];
            operatorCount++;
            double first;
            double second;
            /* if statements used to check if the stack is empty before removing the top value*/
            if (stack.empty() == true)
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            stack.pop(first);
            size--;

            if (stack.empty() == true)
            {
                cerr << "Error: Invalid expression." << endl;
                exit(1);
            }
            stack.pop(second);
            size--;

            if(Operator[operatorCount-1] == '+')
            {
                newValue = first+second;
                operatorCount--;
                stack.push(newValue);
                size++;
            }
            else if(Operator[operatorCount-1] == '-')
            {
                newValue = first-second;
                operatorCount--;
                stack.push(newValue);
                size++;
            }
            else if(Operator[operatorCount-1] == '/')
            {
                if (second == 0)
                {
                    exit(1);
                }
                newValue = first/second;
                operatorCount--;
                stack.push(newValue);
                size++;
            }
            else if(Operator[operatorCount-1] == '*')
            {
                newValue = first*second;
                operatorCount--;
                stack.push(newValue);
                size++;
            }
            else if(Operator[operatorCount-1] == '^')
            {
                newValue = pow(first, second);
                operatorCount--;
                stack.push(newValue);
                size++;

            }


        }
    }
    if (size != 1)
    {
        exit(1);
    }
    else
    {
        cout << newValue << endl;
    }
}
