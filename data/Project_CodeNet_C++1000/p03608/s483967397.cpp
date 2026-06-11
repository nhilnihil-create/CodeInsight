//// Journey of Harry Singh from Diploma in Cse to Red Coder of India.///////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 210
const int MOD = 1000000007;
int dist[maxn][maxn];
constexpr int INF = INT_MAX;
int32_t main(){
int n,m,r,v,u,w;
cin>>n>>m>>r;
vector<int> p(r);
for(int i=0;i<r;i++)cin>>p[i];

sort(p.begin(),p.end());

for(int i=0;i<=maxn;i++)for(int j=0;j<=maxn;j++)if(i!=j)dist[i][j]=INF;


for(int i=1;i<=m;i++)
{
	cin>>v>>u>>w;
	dist[u][v]=dist[v][u]=w;
}

// flyod warshall
for (int k = 1; k <=n; k++)  
for (int i = 1; i <=n; i++)  
for (int j = 1; j <=n; j++)  
dist[i][j]=min(dist[i][k] + dist[k][j],dist[i][j]); 

// now we have  the mindis form each town to each towne     now check the every permutation bro
 int pasn = LLONG_MAX;
    do {
        int ans = 0;
        for (int i = 1; i < r; i++)
            ans += dist[p[i - 1]][p[i]];
        pasn = min(pasn, ans);
    } while (next_permutation(p.begin(), p.end()));
    cout << pasn << endl;




}