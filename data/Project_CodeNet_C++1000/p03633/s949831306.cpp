#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

ll gcd(ll a,ll b){
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b ,a%b);
}
int main(){
    ll n;cin >> n;
    vector<ll>t(n);
    for(int i=0;i<n;i++) cin >> t[i];

    ll lcm = t[0];
    for(int i=1;i<n;i++) lcm = (lcm/gcd(t[i] ,lcm))*t[i];
    cout << lcm << endl;
}