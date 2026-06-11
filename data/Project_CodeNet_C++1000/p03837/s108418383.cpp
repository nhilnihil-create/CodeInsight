#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

int n, m;
VVI g;
map<pair<int, int>, int> edge;

void wf() {
    REP(k,n) {
        REP(i,n) {
            REP(j,n) {
                MIN(g[i][j], g[i][k] + g[j][k]);
                g[j][i] = g[i][j];
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    g.resize(n, VI(n, INF));
    REP(i,m) {
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        g[a][b] = c;
        g[b][a] = c;
        if (a > b) swap(a,b);
        edge[make_pair(a,b)] = c;
    }
    REP(i,n) g[i][i] = 0;

    wf();

    int cnt = m;
    REP(i,n) {
        REP(j,n) {
            REPITR(itr,edge) {
                if (g[i][j] == g[i][itr->e1.e1] + itr->e2 + g[itr->e1.e2][j]) {
                    //cout<<i<<" "<<j<<" "<<itr->e1.e1<<" "<<itr->e1.e2<<" "<<g[i][j]<<" "<<g[i][itr->e1.e1] + edge[itr->e1] + g[itr->e1.e2][j]<<endl;
                    auto tmp = itr;
                    itr--;
                    edge.erase(tmp);
                    cnt--;
                }
            }
        }

        if (edge.empty())
            break;
    }

    cout<<cnt<<endl;

    return 0;
}
