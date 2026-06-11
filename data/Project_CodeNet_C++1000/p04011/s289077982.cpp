#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define pll pair<lli,lli>
#define vi  vector<int>
#define vii vector<pair<int,int>>
#define vll vector<lli>
#define pb  push_back
#define mp  make_pair
#define ss  second
#define ff  first
#define all(x) sort(x.begin(),x.end())
map<int,int>m;
void solve()
{
    int n,k;cin>>n>>k;
    int x,y;cin>>x>>y;
    lli ans=min(n,k);
    ans=ans*x;
    if(k<n)
    {
        int res=n-k;
        ans+=res*y;
    }
    cout<<ans<<endl;

}

int main()
{
    solve();
}
