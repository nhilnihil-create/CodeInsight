#include <bits/stdc++.h>
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
    ll n, a, b;
    cin >> n >> a >> b;
    if(n==1&&a==b)
        cout<<"1";
    else if(n!=1&&a<=b)
        cout<<(n-2)*(b-a)+1;
    else cout<<"0";
}