#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    string s;
    cin>>s;
    string t="YAKI";
    ll ans=0;
    for(ll i=0;i<4;++i){
        if(s[i]==t[i]){
            ans+=1;
        }
    }
    if(ans==4){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
