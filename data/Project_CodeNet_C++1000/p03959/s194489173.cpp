#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {
    const ll MOD = 1e9+7;
    int N; cin >> N;
    vector<ll> T(N); repp(i,0,N) cin >> T[i];
    vector<ll> A(N); repp(i,0,N) cin >> A[i];

    vector<ll> res(N);
    bool can = true;

    res[0] = -T[0];
    repp(i,1,N) {
        can &= T[i] >= T[i-1];
        if (T[i] > T[i-1]) res[i] = -T[i];
        else res[i] = T[i];
    }

    can &= res[N-1] == -A[N-1] || A[N-1] <= res[N-1];
    res[N-1] = -A[0];
    repm(i,N-2,-1) {
        can &= A[i] >= A[i+1];
        if (A[i] > A[i+1]) {
            can &= res[i] == -A[i] || A[i] <= res[i];
            res[i] = -A[i];
        } else res[i] = min(res[i], A[i]);
    }

    ll count = 1;
    repp(i,0,N) {
        if (res[i] < 0) continue;
        count *= res[i];
        count %= MOD;
    }
    if (can) cout << count << endl;
    else cout << 0 << endl;
}
