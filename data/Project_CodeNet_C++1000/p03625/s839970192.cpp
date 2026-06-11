//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    set<ll>s,s1;
    set<ll>:: iterator it;
    vector<ll>v,v1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    sort(a,a+n);
    ll c=0,ans=0,ans1=0;
    if(s.size()==n)
        ans=0;
    else
    {
        for(it=s.begin();it!=s.end();it++)
        {
            int u=upper_bound(a,a+n,*it)-a;
            int l=lower_bound(a,a+n,*it)-a;
            c=u-l;
            if(c>=2)
                v.push_back(*it);
                if(c>=4)
                    v1.push_back(*it);
        }
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end());
        if(v.size()>=2)
        {
            ans=v[v.size()-1]*v[v.size()-2];
        }
        if(v1.size()>=1)
        {
            ans1=v1[v1.size()-1]*v1[v1.size()-1];
        }
        ans=max(ans1,ans);
        //cout<<ans1<<endl;

    }
    cout<<ans<<endl;
}

