#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N;
    cin >> N;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    ll cnt = 0;
    REP(i,0,N) {
        if(A[i] > 2) {
            cnt += (A[i] - 1) / 2;
            A[i] -= (A[i] - 1) / 2 * 2;
        }
    }
    
    ll k = 0;
    while(k < N - 1) {
        while(A[k] == 0) ++k;
        while(k < N && A[k] == 2) {
            A[k] = 0;
            ++k;
            ++cnt;
        }
        while(A[k] == 0) ++k;
        while(A[k] == 1 && k < N - 1) {
            if(A[k+1] > 1) {
                A[k] = 0; --A[k+1];
                ++k;
                ++cnt;
            }
            else if(A[k+1] == 1) {
                A[k] = 0; A[k+1] = 0;
                k += 2;
                ++cnt;
            }
            else k += 2;
        }
    }
    if(A[N-1] == 2) ++cnt;
    PR(cnt);

    return 0;
}

/*



*/