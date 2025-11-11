#include<iostream>
#include<queue>
using namespace std;
void generatebinary(int n){
    queue<string>q; 
    q.push("1");
    for(int i=0;i<10;i++){
string  curr=q.front();
q.pop();

cout<<curr;

if(i<n){
    cout<<" ,";
}

q.push(curr+"0");
q.push(curr+"1");
    }
}

int main(){
    int n=10;
    generatebinary(n);


}