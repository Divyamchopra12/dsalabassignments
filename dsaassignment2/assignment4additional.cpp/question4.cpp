#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int idx = 0;
    int count = 0;
    int n = sandwiches.size();

    while (!q.empty()) {
        if (q.front() == sandwiches[idx]) {
            q.pop();
            idx++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }

        if (count == q.size()) break; // no one wants the top sandwich
    }
    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << countStudents(students, sandwiches);
    return 0;
}
