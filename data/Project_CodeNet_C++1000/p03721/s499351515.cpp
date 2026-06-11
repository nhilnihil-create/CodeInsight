#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,kth,ans,cnt=0,x,kopi;
    cin>>n>>kth;
    vector<pair<ll,ll>>v(n);
    for(i=0; i<n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    for(i=0; i<n; i++)
    {
        cnt+=v[i].second;
        if(cnt>=kth)
            return   cout<<v[i].first<<endl,0;
    }

    return 0;
}



