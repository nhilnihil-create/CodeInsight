#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll i,j;
    ll co=0;
    for(i=0;i<n;i++)cin >> a.at(i);
    for(i=0;i<n;i++){
        if(a.at(a.at(i)-1)==i+1)co++;
    }
    cout << co/2 << endl;
    return 0;
}