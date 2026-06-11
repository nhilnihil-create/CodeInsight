#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    bool flag=false;
    for(int i=0;i<=b;i++){
        if((a*i)%b==c)flag=true;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}