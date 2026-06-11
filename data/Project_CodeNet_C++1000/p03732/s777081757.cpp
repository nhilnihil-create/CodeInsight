#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    vector<ll>a[4];
    ll n,w;
    cin>>n>>w;
    ll w1,v;
    cin>>w1>>v;
    a[0].push_back(v);
    for(int i=1;i<n;i++)
    {
        ll w,x;
        cin>>w>>x;
        a[w-w1].push_back(x);
    }
    for(int i=0;i<4;i++)
    {
        sort(a[i].begin(),a[i].end(),greater<ll>());
    }
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<a[i].size();j++)
        {
            a[i][j]+=a[i][j-1];
        }
    }
    ll val=0;
    for(int i=0;i<=a[0].size();i++)
    {
        for(int j=0;j<=a[1].size();j++)
         {
             for(int k=0;k<=a[2].size();k++)
                {
                    for(int m=0;m<=a[3].size();m++)
                        {
                            if(i*w1+j*(w1+1)+k*(w1+2)+m*(w1+3)<=w)
                            {
                                ll v=0;
                                if(i>0)
                                    v+=a[0][i-1];
                                if(j>0)
                                    v+=a[1][j-1];
                                if(k>0)
                                    v+=a[2][k-1];
                                if(m>0)
                                    v+=a[3][m-1];
                                    if(v>val)
                                        val=v;
                            }
                        }
                }
         }
    }
    cout<<val;
}
