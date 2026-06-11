#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll mod=998244353;

int main(){
    ll x,y;
    cin>>x>>y;
    
    if(x==y){
        cout<<0;
    }else if(y<x){
        cout<<min({abs(y-x)+2,abs(y-(-x))+1});
    }else{
        cout<<min({abs(y-x),abs((-y)-x)+1});
    }
    
}