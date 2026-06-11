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
    int n,l,r,mark[100002]={0},i;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>l>>r;
        mark[l]++;
        mark[r+1]--;
    }
    int ans=0;
    for (i=1;i<=100000;i++)
    {
        mark[i]+=mark[i-1];
        if (mark[i]>0)
            ans++;
    }
    cout<<ans<<endl;
}