#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int j = 0; // index for unique elements

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1]; // add last unique element

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < j; i++)
        cout << arr[i] << " ";
}
