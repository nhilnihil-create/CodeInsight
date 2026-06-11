#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n;
    cin>>n;
    if (n%10==9 || n/10==9)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}