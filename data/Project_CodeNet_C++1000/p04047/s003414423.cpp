#include<bits/stdc++.h>
#define ll long long
#define reg(i,x) for(ll i=0;i<x;i++)
#define regi(i,a,x) for(ll i=a;i<x;i++)
#define rev(i,n) for(ll i=n-1;i>0;i--)
#define vi vector<ll>
#define vc vector<char>
#define vp vector<pair<int,int>>
#define pb push_back
//bool sortbysec(const std::pair<int,int> &a, const std::pair<int,int> &b) return (a.second < b.second);
// sort(v.begin(),v.end(),sortbysec);
//vector<vector<char>>v(n,vector<char>(m));
using namespace std;
int main()
{
    int n;
    cin>>n;
    vi v(2*n);
    reg(i,2*n) cin>>v[i];
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<2*n;i+=2)
    {
        ans+=min(v[i],v[i+1]);
    }
    cout<<ans;
}
