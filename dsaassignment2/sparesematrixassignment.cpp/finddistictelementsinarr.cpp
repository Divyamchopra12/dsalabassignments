#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 3, 6, 3, 2, 1, 7, 9, 9, 8};
    int n = arr.size();

    cout << "Distinct elements are: ";
    for (int i = 0; i < n; i++) {
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                seen = true;
                break;
            }
        }
        if (!seen) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
