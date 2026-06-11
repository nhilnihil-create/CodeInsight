#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

string s;
ll ans=0;

int main(){
    cin>>s;
    string t="CODEFESTIVAL2016";
    for(ll i=0;i<16;++i){
        if(s[i]!=t[i]){
            ans+=1;
        }
    }
    cout<<ans<<endl;
}