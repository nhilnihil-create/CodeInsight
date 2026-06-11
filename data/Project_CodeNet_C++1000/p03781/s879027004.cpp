#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
int main(){
    ll x;
    ll ans=0;
    cin >> x;
    for(ll i=0;i<=pow(10,9);i++){
        if(ans>=x){
            cout << i-1 << endl;
            return 0;
        }
        ans+=i;
    }
}