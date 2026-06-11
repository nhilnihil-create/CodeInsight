#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> red(n,false);
    vector<int> bowl(n,1);
    red[0]=true;
    rep(i,m)
    {
        int x,y;
        cin>>x>>y;
        if(red[x-1])
        {
            red[y-1]=true;
            bowl[x-1]--;
            bowl[y-1]++;
            if(bowl[x-1]==0)red[x-1]=false;
        }
        else
        {
            bowl[x-1]--;
            bowl[y-1]++;
        }
        
    }
    int ans=0;
    rep(i,n)
    {
        if(red[i])
        {
            ans++;
        }
    }
    cout<<ans;

}
