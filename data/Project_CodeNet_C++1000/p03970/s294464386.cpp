#include<bits/stdc++.h>
using namespace std;

using ll=long long;



void solve(){
    string s,c="CODEFESTIVAL2016";
    cin>>s;
    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=c[i])cnt++;
    }
    cout<<cnt<<endl;
}

signed main(){
    //while(1)
    solve();
}