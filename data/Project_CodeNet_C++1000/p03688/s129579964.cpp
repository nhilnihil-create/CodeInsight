#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

bool check(int N, int K, vector<int> a) {
    int count_diff = 0;
    rep(i,N) if (a[i] == K - 1) count_diff++;
    if (N == count_diff) return N == K;
    return (K - count_diff >= 1 && (N - count_diff) / (K - count_diff) >= 2);
}

int main() {

    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    sort(a.begin(), a.end());
    
    if (a[N - 1] - a[0] > 1) {
        cout << "No" << endl;
    }
    if (a[N - 1] - a[0] == 1) {
        if (check(N, a[N - 1], a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if (a[N - 1] - a[0] == 0) {
        if (check(N, a[N - 1], a)) cout << "Yes" << endl;
        else if (check(N, a[N - 1] + 1, a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}