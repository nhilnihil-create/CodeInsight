#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> l(2*n);
    ll i,j;
    for(i=0;i<2*n;i++)cin>>l.at(i);
    sort(l.begin(),l.end());
    ll sum=0;
    for(i=0;i<n;i++)
        sum+=l.at(2*i);
    
    cout << sum <<endl;
    return 0;
}