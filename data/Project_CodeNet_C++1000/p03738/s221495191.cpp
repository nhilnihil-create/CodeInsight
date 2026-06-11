#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    size_t la=a.length();
    size_t lb=b.length();

    if(la>lb) cout<<"GREATER"<<"\n";
    else if(la<lb) cout<<"LESS"<<"\n";
    else{
        if(a>b) cout<<"GREATER"<<"\n";
        else if(a<b) cout<<"LESS"<<"\n";
        else cout<<"EQUAL"<<"\n";
    }
     return 0;
}