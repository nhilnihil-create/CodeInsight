#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//素因数分解
vector<pair<ll,int>> factorize(ll n){
    vector<pair<ll,int>>res;
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        res.emplace_back(i,0);
        while (n%i == 0)
        {
        n /= i;
        res.back().second++;
        }
        
    }
    if(n != 1) res.emplace_back(n,1);
    return res;
}

int main(){
    int x;
    cin >> x;
    int ans;
    for(int i=1;i<x;i++){
        int a = (i*i+i)/2;
        if(x == 2){
            ans = 2;
            break;}
        if(a>=x){
            ans = i;
            break;
        }
    }
    if(x == 1)cout << 1 << endl;
    else cout << ans << endl;
}
