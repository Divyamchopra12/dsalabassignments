#include<iostream>
#include<vector>
using namespace std;
int missingele(vector<int>arr,int n){
    int size=arr.size();
    int xor1=0;
    int xor2=0;
    for(int i=0;i<size;i++){
        xor1^=(i+1);
        xor2^=arr[i];
    }
    xor1^=n;

    return (xor1^xor2);
}
int main(){
    int n=6;
    vector<int>arr={1,3,5,6,4};
    int ele=missingele(arr,6);

    cout<<"the missing element is ::"<<ele;
}