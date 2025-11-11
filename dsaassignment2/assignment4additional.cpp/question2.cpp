#include <iostream>
#include<climits>
#include <queue>
using namespace std;

// Function to find index of minimum element in first n elements
int findMinIndex(queue<int>& q, int sortedIndex) {
    int minIndex = -1; 
    int minValue = INT_MAX;
    int size = q.size();

    for(int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (curr <= minValue && i <= sortedIndex) {
            minIndex = i;
            minValue = curr;
        }

        q.push(curr);
    }

    return minIndex;
}

// Function to bring element at minIndex to rear
void insertMinToRear(queue<int>& q, int minIndex) {
    int size = q.size();
    int minValue;

    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (i == minIndex)
            minValue = curr;
        else
            q.push(curr);
    }

    q.push(minValue);
}

// Function to sort the queue
void sortQueue(queue<int>& q) {
    int n = q.size();

    for(int i = 1; i <= n; i++) {
        int minIndex = findMinIndex(q, n - i);
        insertMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
