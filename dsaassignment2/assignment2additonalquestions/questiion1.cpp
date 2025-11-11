#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int diff) {

    unordered_map<int,int> mp;
    int count = 0;

    // store all elements
    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    // check pairs
    for (int i = 0; i < arr.size(); i++) {       
        if (mp.find(arr[i] + diff) != mp.end())
            count++;

        if (diff != 0 && mp.find(arr[i] - diff) != mp.end())
            count++;
    }

    return count / 2; // remove double counting
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int diff = 2;

    cout << "Count = " << countPairs(arr, diff);
    return 0;
}
