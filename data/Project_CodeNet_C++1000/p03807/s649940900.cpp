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
    int n,b=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2!=0)
            b++;
    }
    if(b%2!=0)
        cout<<"NO";
    else
        cout<<"YES";
}