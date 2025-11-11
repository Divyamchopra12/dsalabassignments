#include <bits/stdc++.h>
using namespace std;

bool possibleSplit(string s) {
    vector<int> freq(26, 0);

    for (char c : s)
        freq[c - 'a']++;

    for (int f : freq)
        if (f >= 3)
            return true;

    return false;
}

int main() {
    string s = "ababa";
    
    if (possibleSplit(s))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
