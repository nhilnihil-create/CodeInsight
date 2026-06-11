#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int first=n%10;
    n=n/100;
    int second=n%10;
    if(second==first){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}