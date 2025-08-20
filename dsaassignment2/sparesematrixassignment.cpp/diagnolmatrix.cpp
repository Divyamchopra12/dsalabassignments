#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the no of rows and column in matrix::"<<endl;
    cin>>n;
    int arr[n][n];
    int temp[3]={1,2,3};// elements at daignol of matrix;
    cout<<"enter the elements of array::"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=temp[i];
            }
        }
        
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}