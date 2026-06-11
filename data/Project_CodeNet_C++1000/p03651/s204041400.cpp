#include <bits/stdc++.h>
#define ll long long 
#define done(x) {cout<<x<<"\n";return 0;} 
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    ll gcd=arr[0];
    for(int i=1;i<n;i++) gcd=__gcd(gcd,arr[i]);
    if((k%gcd) || arr[n-1]<k) done("IMPOSSIBLE\n")
    done("POSSIBLE\n") 
}