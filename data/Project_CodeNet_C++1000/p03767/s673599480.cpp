#include <bits/stdc++.h>
#include<string.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define nl endl
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio;
    ll i,n,s=0;
    cin>>n;
    ll m=3*n;
    ll a[m];
    for(i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a,a+m);
    for(i=n;i<m;i=i+2){
        s+=a[i];
    }
    cout<<s;
}