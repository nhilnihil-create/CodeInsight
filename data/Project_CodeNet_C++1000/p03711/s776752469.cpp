#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 1e5+10;

using namespace std;

main()
{
    fast;
    int x,y;
    int mark[13]={0,1,3,1,2,1,2,1,1,2,1,2,1};
    cin>>x>>y;
    if (mark[x]==mark[y])
        cout<<"Yes\n";
    else
        cout<<"No\n";
}