#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define rt return
using dbl = double;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

int main(){
    ll K;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K;
    int N = 50;
    ll A = K / N;
    vll a(N);
    iota(all(a), A);
    rep(i, K%N) {
        ll mi = *min_element(all(a));
        rep(j, N) {
            if (a[j] == mi)a[j] += N;
            else a[j]--;
        }
    }
    cout << N << endl;
    rep(i, N)cout << a[i] << (i != N - 1 ? ' ' : '\n');
}
