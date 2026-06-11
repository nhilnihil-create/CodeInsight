#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M));
    rep(i, N)rep(j, M){
        cin >> a[i][j];
        a[i][j]--;
    }

    int ans = N;
    vector<int> done(M, false);

    rep(loop, M){
        vector<int> use(M, 0);
        rep(i, N)rep(j, M){
            if(!done[a[i][j]]){
                use[a[i][j]]++;
                break;
            }
        }
        int maximum = -1, pos = -1;
        rep(i, M)if(chmax(maximum, use[i]))pos = i;
        chmin(ans, maximum);
        done[pos] = true;
    }

    cout << ans << endl;
    return 0;

}