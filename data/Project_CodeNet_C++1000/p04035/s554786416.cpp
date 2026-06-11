#include<bits/stdc++.h>
using namespace std;
#define lli    long long int
#define pii    pair<int,int>
#define pll    pair<lli,lli>
#define vi     vector<int>
#define vii    vector<pair<int,int>>
#define vll    vector<lli>
#define pb     push_back
#define mp     make_pair
#define ss     second
#define ff     first
#define all(x) sort(x.begin(),x.end())
#define BLACK  0
#define WHITE  1

void solve()
{
    int n,k;cin>>n>>k;
    int lol[n+1];
    lli sum=0;
    for(int i=1;i<=n;i++)cin>>lol[i];
    for(int i=1;i<=n;i++)sum+=lol[i];
    if(sum<k)
    {
        cout<<"Impossible\n";return;
    }
    vector<int>ans;
    for(int i=1;i<n;i++)
    {
        if(lol[i]+lol[i+1]>=k)
        {
            if(i>1)
            {
                for(int j=1;j<i;j++)ans.pb(j);
            }
            if(i+1 < n)
            {
                for(int j=n-1;j>i;j--)ans.pb(j);
            }
            ans.pb(i);
            cout<<"Possible\n";
            for(int j:ans)cout<<j<<endl;
            return;
        }
    }
    cout<<"Impossible\n";return;

}
int main()
{
    solve();
}
