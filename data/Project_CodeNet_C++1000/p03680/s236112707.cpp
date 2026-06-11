#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int>adj[MAX];
int v[MAX],d[MAX],nxt[MAX];
void dfs(int src)
{
    v[src]=1;
    for(int i=0; i<adj[src].size(); i++)
    {
        int c=adj[src][i];
        if(v[c]==0)
        {
            d[c]=d[src]+1;
            dfs(c);
        }
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        nxt[i]=a;

    }
    int cnt=0,cur=1,f=0;
    while(!v[cur])
    {
        cnt++;
        v[cur]=1;
        cur=nxt[cur];
        if(cur==2){
         f=1;
            break;
        }
    }
    if(!f)
        cout<<"-1"<<endl;
    else
        cout<<cnt<<endl;


    return 0;
}
