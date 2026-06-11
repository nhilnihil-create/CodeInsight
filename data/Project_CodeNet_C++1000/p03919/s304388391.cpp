#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ll h,w;
    cin>>h>>w;
    string s;
    ll a,b;
    for(ll i=0;i<h;++i){
        for(ll j=0;j<w;++j){
            cin>>s;
            if(s=="snuke"){
                a=j;
                b=i+1;
                break;
            }
        }
    }
    cout<<(char)('A'+a)<<b<<endl;
}