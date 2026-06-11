#include <bits/stdc++.h>
#define ll long long
#define done(x) {cout<<x<<"\n";return 0;}  
using namespace std;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>b || (n==1 && a!=b)) done(0)
    if((n==1 && a==b) || n==2) done(1)
    ll l=a+b,r=a+b;
    l+=(n-2)*a; r+=(n-2)*b;
    cout<<r-l+1<<"\n";
}