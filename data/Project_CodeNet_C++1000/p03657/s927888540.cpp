#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    bool ok=false;
    if(a%3==0||b%3==0||(a+b)%3==0)ok=true;
    if(ok)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}