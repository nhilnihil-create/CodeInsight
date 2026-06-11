#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = (a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (a); i <= (long long)(n); i++)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

struct Edge {
    int cost, to;
    Edge(int to_, int cost_) : 
        to(to_), cost(cost_) { } 
};

int main(void)
{
    int n, m;
    cin >> n >> m;

    v2_int dist(n, v_int(n, INF));
    v_int prev(n, -1);
    v_int a(m), b(m), c(m); 

    map<pii, bool> used_path;

    irep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    irep(i, n) { dist[i][i] = 0; }

    irep(k, n) {
        irep(i, n) {
            irep(j, n) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int ans = m;
    irep(i, m) {
        bool shortest = false;
        irep(j, n) {
            if(dist[j][b[i]] == dist[j][a[i]] + c[i]) shortest = true; 
        }
        if(shortest) { ans--; }
    }
    cout << ans << endl;

    return 0;
}
/** atcoder **/
