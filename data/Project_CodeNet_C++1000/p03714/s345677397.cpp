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
    int n,i;
    cin>>n;
    ll a[3*n];
    for (i=0;i<3*n;i++)
        cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> left_part;
    priority_queue<int> right_part;
    ll left[3*n],right[3*n];
    ll cur_sum=0;
    for (i=0;i<3*n;i++)
    {
        left_part.push(a[i]);
        cur_sum+=a[i];
        if (left_part.size()>n)
        {
            cur_sum-=left_part.top();
            left_part.pop();
        }
        left[i]=cur_sum;
    }
    cur_sum=0;
    for (i=3*n-1;i>=0;i--)
    {
        right_part.push(a[i]);
        cur_sum+=a[i];
        if (right_part.size()>n)
        {
            cur_sum-=right_part.top();
            right_part.pop();
        }
        right[i]=cur_sum;
    }
    ll ans=-1e18;
    for (i=n-1;i<2*n;i++)
        ans=max(ans,left[i]-right[i+1]);
    cout<<ans<<endl;
}