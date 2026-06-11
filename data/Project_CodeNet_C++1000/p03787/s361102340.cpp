
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define MAX_N 100000

vector<vi> g(MAX_N);
vi used(MAX_N,-1);
bool x;
void dfs(int now){
    rep(i,g[now].size()){
        int ne = g[now][i];
        if(used[ne]==used[now])x = false;
        if(used[ne]==-1){
            used[ne] = 1 - used[now];
            dfs(ne);
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll a=0,b=0,c=0;
    rep(i,n)if(used[i]==-1){
        used[i] = 0;
        if(g[i].size()==0){
            a++;
        }else{
            x = true;
            dfs(i);
            if(x)b++;
            else c++;
        }
    }
   // cout << a << " " << b << " " << c << endl;
    cout << 2*b*b + 2*b*c + c*c + a*a + 2*a*(n-a) << endl;
}
