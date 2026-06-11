#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int main(){
    int N;
    string s;
    cin >> N;
    cin >> s;
    char ans[N];
    char c[2] = {'S', 'W'};
    rep(i, 2){
        rep(j, 2) {
            ans[0] = c[i];
            ans[1] = c[j];
            REP(k, 2, N) {
                if (ans[k-1] == 'S' && ans[k-2] == 'S' && s[k-1] == 'o' || ans[k-1] == 'W' && ans[k-2] == 'W' && s[k-1] == 'o' || ans[k-1] == 'S' && ans[k-2] == 'W' && s[k-1] == 'x' || ans[k-1] == 'W' && ans[k-2] == 'S' && s[k-1] == 'x') {
                    ans[k] = 'S';
                } else {
                    ans[k] = 'W';
                }
            }
            if ((s[0] == 'o' && ans[N-1] == 'S' && ans[1] == 'S' && ans[0] == 'S' || s[0] == 'o' && ans[N-1] == 'W' && ans[1] == 'W' && ans[0] == 'S' || s[0] == 'o' && ans[N-1] == 'W' && ans[1] == 'S' && ans[0] == 'W' || s[0] == 'o' && ans[N-1] == 'S' && ans[1] == 'W' && ans[0] == 'W' || s[0] == 'x' && ans[N-1] == 'S' && ans[1] == 'W' && ans[0] == 'S' || s[0] == 'x' && ans[N-1] == 'W' && ans[1] == 'S' && ans[0] == 'S' || s[0] == 'x' && ans[N-1] == 'S' && ans[1] == 'S' && ans[0] == 'W' || s[0] == 'x' && ans[N-1] == 'W' && ans[1] == 'W' && ans[0] == 'W') && (s[N-1] == 'o' && ans[N-1] == 'S' && ans[N-2] == 'S' && ans[0] == 'S' || s[N-1] == 'o' && ans[N-1] == 'S' && ans[N-2] == 'W' && ans[0] == 'W' || s[N-1] == 'o' && ans[N-1] == 'W' && ans[N-2] == 'S' && ans[0] == 'W' || s[N-1] == 'o' && ans[N-1] == 'W' && ans[N-2] == 'W' && ans[0] == 'S' || s[N-1] == 'x' && ans[N-1] == 'S' && ans[N-2] == 'W' && ans[0] == 'S' || s[N-1] == 'x' && ans[N-1] == 'S' && ans[N-2] == 'S' && ans[0] == 'W' || s[N-1] == 'x' && ans[N-1] == 'W' && ans[N-2] == 'S' && ans[0] == 'S' || s[N-1] == 'x' && ans[N-1] == 'W' && ans[N-2] == 'W' && ans[0] == 'W')) {
                rep(k, N){
                    cout << ans[k];
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

}