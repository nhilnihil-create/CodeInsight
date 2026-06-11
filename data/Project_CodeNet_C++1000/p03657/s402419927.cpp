#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    int a,b;
    cin>>a>>b;
    if(a%3==0||b%3==0||(a+b)%3==0){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
}

signed main(){
    //while(1)
    solve();
}