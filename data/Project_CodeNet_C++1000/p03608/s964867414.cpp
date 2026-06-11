#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const int INF = 1e9;
vecveci dist(210,veci(210,INF));

int main() {
    int N,M,R; cin >> N >> M >> R;

    vector<int> ri(R);
    REP(i,R) {
        cin >> ri[i];
        ri[i]--;
    }
    
    REP(i,M) {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    REP(k,N) REP(i,N) REP(j,N) dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    int ans = INF;

    sort(ri.begin(),ri.end());

    do{
        int total = 0;
        REP(i,R-1) {
            total += dist[ri[i]][ri[i+1]];
        }
        chmin(ans,total);
    }while(next_permutation(ri.begin(),ri.end()));

    cout << ans << endl;
}
