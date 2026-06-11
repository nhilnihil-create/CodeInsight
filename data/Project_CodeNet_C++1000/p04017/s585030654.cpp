#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;
    vector<int> x(N);
    rep(i, N)cin >> x[i];
    int L, Q;
    cin >> L >> Q;

    vector<vector<int>> canmove(N, vector<int>(20));
    rep(i, N)canmove[i][0] = upper_bound(all(x), x[i] + L) - x.begin() - 1;
    rep(j, 19)rep(i, N)canmove[i][j + 1] = canmove[canmove[i][j]][j];

    rep(loop, Q){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b)swap(a, b);
        int ans = 0;
        for(int i = 19; i >= 0; i--){
            if(canmove[a][i] < b){
                ans += 1 << i;
                a = canmove[a][i];
            }
        }
        if(a != b)ans++;
        cout << ans << endl;
    }

}