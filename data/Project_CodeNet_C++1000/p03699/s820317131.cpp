#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    ll t,i,j,n,x,sum=0;
    cin>>n;
    vector<ll>v;
    for(i=0; i<n; i++)
    {
        cin>>x;
        if(x%10!=0) v.push_back(x);
        sum+=x;
    }
    if(v.size()==0&&sum%10==0)
   return  cout<<0<<endl,0;
   if(sum%10==0)
   sum-=*min_element(v.begin(),v.end());

    cout<<sum<<endl;
    return 0;
}



