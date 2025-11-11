#include <bits/stdc++.h>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();

    // Count number of 2's
    int count2 = 0;
    for (int x : arr) {
        if (x == 2) count2++;
    }

    int i = n - 1;
    int j = n + count2 - 1;  // expanded index

    // Process from end
    while (i >= 0) {
        if (j < n)
            arr[j] = arr[i];  // copy element

        if (arr[i] == 2) {
            j--;
            if (j < n)
                arr[j] = 2;   // duplicate 2
        }

        i--;
        j--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 5};

    duplicateTwos(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}
