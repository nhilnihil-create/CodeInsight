#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
vector<int>v[100000];
vector<int>ans;
int visited[100000];
void add(deque<int>&dq)
{
    int x=dq.front();
    for(auto c:v[x])
    {
        if(!visited[c])
        {
            visited[c]=1;
            dq.push_front(c);
            add(dq);
            return ;
        }
    }
    int y=dq.back();
    for(auto c:v[y])
    {
        if(!visited[c])
        {
            visited[c]=1;
            dq.push_back(c);
            add(dq);
            return ;
        }
    }
}
int32_t main() {
    nitin;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    deque<int>dq;
    visited[0]=1;
    dq.push_back(0);
    add(dq);
    cout<<dq.size()<<endl;
    while(!dq.empty())
    {
        cout<<dq.front()+1<<" ";
        dq.pop_front();
    }
    return 0;
}