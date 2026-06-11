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

int main(){
    cin>>s;
    for(ll i=0;i<4;++i){
        cout<<s[i];
    }
    cout<<' ';
    for(ll i=4;i<12;++i){
        cout<<s[i];
    }
    cout<<endl;
}