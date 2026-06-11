#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll x;
    cin >> x;
    ll cnt=0;
    ll dx=x/11;
    cnt+=dx*2;
    ll sum=dx*11;
    if(sum<x){
        sum+=6;
        cnt++;
    }
    if(sum<x){
        sum+=5;
        cnt++;
    }
    cout << cnt << endl;
}