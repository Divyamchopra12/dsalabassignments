#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of rows and columns::" << endl;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int x = 10;
    int a[x];
    cout << "enter the elements of input array" << endl;
    for (int i = 0; i < x; i++)
    {
        cin >> a[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = a[k];
                k++;
            }
        }
    }

    cout << "upper triangularmatrix is prsented as" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}