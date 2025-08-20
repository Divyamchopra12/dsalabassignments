#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size()-1-i;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }

        }
    }
}
int main(){
    vector<int>arr={64, 35, 25, 12, 22, 11, 90};
    bubblesort(arr);


cout<<"array after sorting becomes:";
for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
}
}