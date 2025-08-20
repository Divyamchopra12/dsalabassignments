#include <iostream>
#include <vector>
using namespace std;
int count_inversions(vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j] && i < j)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {5, 3, 6, 3, 2, 1, 7, 9, 9, 8};
    int n = arr.size();
    int inversions = count_inversions(arr);
    cout << "the total number of inversion in arrays are " << inversions;
}