#include <bits/stdc++.h>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1; // since natural numbers 1..n
    int n = q.size();

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == expected)
            expected++;
        else {
            if (!st.empty() && st.top() < x)
                return false;
            st.push(x);
        }
    }
    
    while (!st.empty()) {
        if (st.top() != expected)
            return false;
        st.pop();
        expected++;
    }

    return true;
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << (checkSorted(q) ? "Yes" : "No");
    return 0;
}
