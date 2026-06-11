#include<bits/stdc++.h>
using namespace std;
#define int            int64_t
#define double         long double
#define nitro          ios_base::sync_with_stdio(false);cin.tie(0);
#define vi             vector<int64_t>
#define vpii           vector<pair<int,int>>
#define si             set<int>
#define pub            push_back
#define puf            push_front
#define pob            pop_back
#define pof            pop_front
#define PI             3.1415926535897932384626433832795
#define read(a)        for(auto& x : a) cin>> x
#define endl           '\n'
#define gap            ' '
#define min3(a,b,c)    min(a, min(b, c))
#define max3(a,b,c)    max(a, max(b, c))
#define MOD            1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int32_t main()
{
    nitro
    int n,k;cin>>n>>k;
    vpii a(n);
    for(auto&x:a) cin>>x.first>>x.second;
    sort(a.begin(),a.end());
    for(int i=1;i<n;++i) a[i].second+=a[i-1].second;
    for(auto x:a) if(x.second>=k) return cout<<x.first,0;
}
    
