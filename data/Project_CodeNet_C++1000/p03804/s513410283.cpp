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

    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];

    rep(i,N-M+1) rep(j,N-M+1) {
        bool flag = true;
        rep(k,M) if (A[i + k].substr(j,M) != B[k]) flag = false;
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}