#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9+7;
const long long MAXN = 1e5+5;
long long arr[MAXN];
long long arr2[MAXN];
long long dp[MAXN];
long long dp2[MAXN];
int main(){
    long long x,y;
    cin>>x>>y;
    if(abs(x-y) <=1){
        cout<<"Brown"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
}