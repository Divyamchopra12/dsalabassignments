#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlag(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0};

    dutchNationalFlag(arr);

    for (int x : arr) cout << x << " ";
    return 0;
}
