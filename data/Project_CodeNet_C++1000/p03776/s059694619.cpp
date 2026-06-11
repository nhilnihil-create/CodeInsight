#include <bits/stdc++.h>

#define PI 3.14159265359
#define EPS 1e-16
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

ll p[100][100];

int main(void)
{
    int n, a, b;
    cin >> n >> a >> b;

    v_ll v(n);

    irep(i, n) { cin >> v[i]; }
    sort(v.rbegin(), v.rend());

    double ans = 0;  

    irep(i, a) { ans += v[i]; }
    ans /= a;

    printf("%.6f\n", ans);
    
    irep(i, 51) { 
        p[i][0] = 1; 
        p[i][i] = 1;
    }
    
    irep2(i, 0, 50) {
        irep2(k, 0, i+1) {
            p[i+1][k] = p[i][k];
            if(k>0) { p[i+1][k] += p[i][k-1]; }
        }
    }

    ll max_v = v[0];
    int max_cnt = 1;

    irep2(i, 1, n-1) {
        if(max_v == v[i]) { max_cnt++; }
    }
    
    ll comb = 0;
    if(max_cnt >= a) {
        irep2(i, a, min(b, max_cnt)) {
            comb += p[max_cnt][i];
        }
        cout << comb << endl;
        return 0;
    }

    max_v = v[0];
    max_cnt = 1;

    irep2(i, 1, a-1) {
        if(max_v != v[i]) {
            max_v = v[i];
            max_cnt = 1;
        } else {
            max_cnt++;
        }
    }
    
    int k = max_cnt;

    irep2(i, a, n-1) {
        if(max_v == v[i]) {
            max_cnt++;
        }
    }
    cout << p[max_cnt][k] << endl;

    return 0;
}

