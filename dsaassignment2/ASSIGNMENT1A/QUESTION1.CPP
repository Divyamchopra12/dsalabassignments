#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = val;
    n++;
}

void del() {
    int pos;
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;

    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

void linearSearch() {
    int val;
    cout << "Enter element to search: ";
    cin >> val;

    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: create(); break;
        case 2: display(); break;
        case 3: insert(); break;
        case 4: del(); break;
        case 5: linearSearch(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
