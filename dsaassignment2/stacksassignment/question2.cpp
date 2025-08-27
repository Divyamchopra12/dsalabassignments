#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;   // if you want spaces too, use getline(cin, str);

    stack<char> st;

    // Push all characters into stack
    for (char c : str) {
        st.push(c);
    }

    // Pop characters to form reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
