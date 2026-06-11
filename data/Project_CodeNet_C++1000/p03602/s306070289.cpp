#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

llint WarshallFloyd(int N, vector< vector<int> > &G){
    llint ans = 0;
    vector< vector<int> > G_str(G);
    REP(i, N) REP(j,N) REP(k, N){
        if(i == j || i == k) continue;
        if(G[j][k] > G[j][i] + G[i][k]){
            return -1;
        }else if(G[j][k] == G[j][i] + G[i][k]){
            G_str[j][k] = 0;
        }
    }
    // REP(i, N){
    //     REP(j, N){
    //     cout << G_str[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    REP(i, N)REP(j, N){
        ans += G_str[i][j];
    }
    return ans/2;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector< vector<int> > G(N, vector<int>(N));
    REP(i, N)REP(j, N){
        cin >> G[i][j];
    }
    cout << WarshallFloyd(N, G) << "\n";
    
    return 0;
}
