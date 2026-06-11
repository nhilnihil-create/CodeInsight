#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;


int main(){
    int N;
    ll W;
    cin >> N >> W;

    vector<vector<ll>> wv(4, vector<ll>());
    ll w0;
    rep(i,N){
        ll w, v; cin >> w >> v;
        if (i==0) {
            wv[0].push_back(v);
            w0 = w;
        }
        else {
            wv[w-w0].push_back(v);
        }
    }

    rep(i,4){
        sort(wv[i].begin(), wv[i].end(), greater<ll>());
    }

    vector<vector<ll>> s(4, vector<ll>(N+1,0));
    rep(i, 4){
        rep(j, wv[i].size()){
            s[i][j+1] = s[i][j] + wv[i][j];
        }
    }
 
    ll ans = 0;
    for(int i = 0; i <= wv[0].size(); i++){
        for (int j = 0; j <= wv[1].size(); j++){
            for (int k = 0; k <= wv[2].size(); k++){
                for (int l = 0; l <= wv[3].size(); l++){
                    ll value = s[0][i] + s[1][j] + s[2][k] + s[3][l];
                    ll weight = i*w0 + j*(w0+1) + k*(w0+2) + l*(w0+3);
                    if (weight <= W){
                        ans = max(ans, value);
                    }
                }
            }
        }
    }
    cout << ans << endl;

}