#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

vector<int> g[100005];
vector<int> res[100001];

int dp(int x){
    if(g[x].empty()) return 0;

    REP(i, g[x].size()) res[x].push_back(dp(g[x][i]));
    sort(all(res[x]), greater<>());

    int ret = 0;
    REP(i, res[x].size()) chmax(ret, res[x][i] + i + 1);

    return ret;
}

int main() {
    int N;
    cin >> N;

    for(int i = 2; i <= N; i++) {
        int a;
        cin >> a;

        g[a].push_back(i);
    }

    cout << dp(1) << endl;

    return 0;
}
