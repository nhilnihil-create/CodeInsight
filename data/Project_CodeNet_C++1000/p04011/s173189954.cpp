#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

    ll n,k,x,y;             cin>>n>>k>>x>>y;
    ll a=min(n,k),b=n-a;
    cout<<a*x+b*y;

    return 0;
}
