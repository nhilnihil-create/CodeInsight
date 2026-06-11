#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    string S, T;
    cin >> S >> T;

    int s_sz = (int)S.size();
    int t_sz = (int)T.size();

    vector<int> sa(s_sz + 1, 0), sb(s_sz + 1, 0);
    vector<int> ta(t_sz + 1, 0), tb(t_sz + 1, 0);

    rep(i, s_sz){
        if(S[i] == 'A')sa[i + 1]++;
        else sb[i + 1]++;
        sa[i + 1] += sa[i];
        sb[i + 1] += sb[i];
    }

    rep(i, t_sz){
        if(T[i] == 'A')ta[i + 1]++;
        else tb[i + 1]++;
        ta[i + 1] += ta[i];
        tb[i + 1] += tb[i];
    }

    int Q;
    cin >> Q;

    rep(loop, Q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        int sd = (sa[b] - sa[a]) - (sb[b] - sb[a]);
        int td = (ta[d] - ta[c]) - (tb[d] - tb[c]);
        if((sd - td) % 3 == 0)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}