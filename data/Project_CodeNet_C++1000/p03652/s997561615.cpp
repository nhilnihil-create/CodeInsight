#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,M,ans = 303;
    cin >> N >> M;
    vector<vector<int>> A(N,vector<int>(M));
    rep(i,N)rep(j,M){
        cin >> A[i][j];
        A[i][j]--;
    }
    // まず全てのスポーツ大会を開催する 
    // そのときの参加人数を求める
    set<int> st;
    rep(i,M)st.insert(i);
    while(st.size()){
        vector<int> cnt(M);
        // ここで現在の参加人数を出す
        rep(i,N)rep(j,M){
            if(st.count(A[i][j])){
                cnt[A[i][j]]++;
                break;
            }
        }
        int del = -1;
        int mx = 0;
        rep(i,M){
            if(mx<cnt[i]){
                mx = cnt[i];
                del = i;
            }
        }
        st.erase(del);
        ans = min(ans,mx);
    }
    cout << ans << endl;
}