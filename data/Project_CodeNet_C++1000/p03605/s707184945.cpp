#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag=false;
    while(n>0){
        if(n%10==9)flag=true;
        n/=10;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}