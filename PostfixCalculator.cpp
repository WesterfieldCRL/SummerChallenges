#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main ()
{
    stack<int> operatingStack;
    string input;
    int num1, num2, result;

    cout << "Input DONE to finish and return result" << endl;
    cout << "input numbers or operands (operands are +, -, *, and /)" << endl;
    do
    {
        cin >> input;

        if (input == "+" || input == "-" || input == "*" || input == "/")
        {
            int num2 = operatingStack.top();
            operatingStack.pop();
            int num1 = operatingStack.top();
            operatingStack.pop();

            if (input == "+")
            {
                result = num1 + num2;
            }
            else if (input == "-")
            {
                result = num1 - num2;
            }
            else if (input == "*")
            {
                result = num1 * num2;
            }
            else if (input == "/")
            {
                result = num1 / num2;
            }
            operatingStack.push(result);
        }
        else if (input == "DONE")
        {
            result = operatingStack.top();
            break;
        }
        else
        {
            //validate that it is a number?
            operatingStack.push(stoi(input));
        }
    } while (!operatingStack.empty());

    cout << "result is: " << result << endl;

    return 0;
}