#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>arr,int target){
    int st=0;
    int end=arr.size()-1;
    int ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target){ 
            ans=mid;}
            if(arr[mid]<target){
                st=mid+1;// move to right side of array
            }else{
                end=mid-1;// move to left side of array
            }
        
    } return ans;

}
int main(){
    vector<int>arr={1,9,11,15,90,300};
    int target=11;
   int result= binarysearch(arr,target);
    cout<<"the element is find at the index::"<<result;
}
