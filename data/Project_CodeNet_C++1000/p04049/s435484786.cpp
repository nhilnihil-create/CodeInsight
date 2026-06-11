#include <bits/stdc++.h>
#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x,y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m)
{
    return power(a, m - 2, m);
}
void dfs(int idx,vector<int>*tree,vector<int>&visited)
{
    for(auto c:tree[idx])
    {
        if(visited[c]==-1)
        {
            visited[c]=visited[idx]+1;
            dfs(c,tree,visited);
        }
    }
}
int32_t main()
{
    nitin;
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>tree[n];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int>irritation[n];
    set<pair<int,int>>s;
    vector<int>cnt_irri(n,0);
    for(int i=0;i<n;i++)
    {
        vector<int>visited(n,-1);
        visited[i]=0;
        dfs(i,tree,visited);
        for(int j=0;j<n;j++) {
            if (visited[j] > k) {
                irritation[i].push_back(j);
                cnt_irri[j]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(cnt_irri[i]!=0)
        s.insert({cnt_irri[i],i});
    }
    int cnt=0;
    vector<int>visited(n,0);
    while(!s.empty())
    {
        auto it=prev(s.end());
        int idx=it->second;
        int its_irri=it->first;
        visited[idx]=1;
        cnt_irri[idx]=0;
        cnt++;
        s.erase(it);
        for(auto c:irritation[idx])
        {
            if(visited[c]!=1)
            {
                s.erase({cnt_irri[c],c});
                cnt_irri[c]--;
                if(cnt_irri[c]>=1)
                {
                    s.insert({cnt_irri[c],c});
                }
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}