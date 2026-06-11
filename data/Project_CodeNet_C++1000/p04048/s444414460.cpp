#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
const int maxm=2e6+5;
ll n,x;
signed main(){
    cin>>n>>x;
    cout<<3*(n-__gcd(n,x))<<endl;
    return 0;
}
