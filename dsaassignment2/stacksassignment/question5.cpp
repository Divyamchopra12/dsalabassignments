#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {
        // If operand, push to stack
        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char digit to int
        }
        // If operator, pop two operands and apply
        else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': {
                    int res = 1;
                    for (int i = 0; i < op2; i++) res *= op1;
                    st.push(res);
                    break;
                }
            }
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "The evaluated result is: " << result << endl;

    return 0;
}
