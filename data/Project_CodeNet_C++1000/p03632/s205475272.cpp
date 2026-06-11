#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int ans = min(B, D) - max(A, C);
    if (ans < 0) ans = 0;

    cout << ans << endl;
    
    return 0;
}