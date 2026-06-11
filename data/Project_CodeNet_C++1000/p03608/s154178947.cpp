#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e9
#define vec vector
#define each(i, mp) for(auto& i:mp)
int N, M, R;
int res;
bool used[8];
vec<vec<int>> dist(201, vec<int>(201, inf));
vec<int> r(8);

void dfs(int c, int las, ll d){
    if (c == R){
        if (res > d){
        	res = d;
        }
        return;
    }
    rep(i, R)if(!used[i])
    {
        used[i] = true;
        if (las == -1){
        	dfs(c+1, i, 0);
        }else{
         	dfs(c+1, i, d+dist[r[las]][r[i]]);
        }
        used[i] = false;
    }
}

int main(){
    cin >> N >> M >> R;
    rep(i, R){
    	cin >> r[i];
      	r[i]--;
    }
    rep(i, N) dist[i][i] = 0;

    int a, b, c;
    rep(i, M){
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    rep(k, N) rep(i, N) rep(j, N) {
        if (dist[i][j] > dist[i][k] + dist[k][j]){
            dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
    
    res = inf;
    dfs(0,-1,0);
    cout << res << endl;
}