#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;
typedef long long ll;

int main() {

    int N;
    cin >> N;
    vector<int> p(N);
    rep(i,N) {
        cin >> p[i];
        p[i]--;
    }
    
    vector<int> a(N, 0), b(N, 0);
    rep(i,N) {
        a[i] = 1 + i;
        b[i] = N - i;
    }
    rep(i,N) {
        rep(j,N) {
            if (j <= p[i]) b[j] += i;
            if (j >= p[i]) a[j] += i;
        }
    }
    rep(i,N) cout << a[i] << (i == N - 1 ? "\n" : " ");
    rep(i,N) cout << b[i] << (i == N - 1 ? "\n" : " ");

    return 0;
}