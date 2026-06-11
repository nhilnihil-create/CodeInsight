#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,x;cin>>n>>x;
    cout<<3*(n-__gcd(n,x));
}

