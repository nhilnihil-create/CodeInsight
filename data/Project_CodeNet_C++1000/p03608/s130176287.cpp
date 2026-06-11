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

void warshall_floyd(int n, v2_ll &dist)
{
    irep(i, n) { dist[i][i] = 0; }

    irep(k, n) {
        irep(i, n) {
            irep(j, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(void)
{
    int n, m, r;
    cin >> n >> m >> r;

    v_int vec_r(r);
    irep(i, r) {
        cin >> vec_r[i];
        vec_r[i]--;
    }

    v2_ll dist(n, v_ll(n, LINF));

    irep(i, m) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;
    }
    
    warshall_floyd(n, dist);

    ll ans = LINF;

    v_int index(r);
    irep(i, r) { index[i] = i; }

    do {
        ll d = 0;
        irep(i, r-1) {
            d += dist[vec_r[index[i]]][vec_r[index[i+1]]];  
            //cout << vec_r[i] +1<< "<->" << vec_r[i+1] +1<< "," <<  dist[vec_r[i]][vec_r[i+1]] << ",";  
        }
        ans = min(ans, d);
        //cout << "ans," << ans << endl;
    } while(next_permutation(index.begin(), index.end()));

    cout << ans << endl;
    return 0;
}
/** atcoder **/
