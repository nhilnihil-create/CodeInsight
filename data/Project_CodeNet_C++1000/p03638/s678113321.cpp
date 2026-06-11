#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N,0);
    rep(i,N) cin >> a[i];

    vector<vector<int>> ans(H, vector<int>(W, 0));
    int index = 0;
    rep(i,H){
        if (i % 2 == 0){
            for (int j = 0; j < W; j++){
                ans[i][j] = index;
                if (--a[index] == 0) index++;
            }
        }
        else{
            for (int j = W-1; j >= 0; j--){
                ans[i][j] = index;
                if (--a[index] == 0) index++;
            }
        }
    }

    rep(i,H){
        rep(j,W){
            if(j != 0) cout << " ";
            cout << ans[i][j]+1;
        }
        cout << endl;
    }

}