#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N, K;
int A[100500];
ll B[100500];

int main() {
    //cout.precision(10);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i];
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        if((K & A[i]) == A[i]) ans += B[i];
    }
    int val = 1;
    int index = 0;
    while(index <= 30) {
        if(((K >> index) & 1)) {
            int now = K - val;
            now |= (val - 1);
            ll now_ans = 0;
            for(int i = 1; i <= N; i++) {
                if((now & A[i]) == A[i]) now_ans += B[i];
            }
            ans = max(ans, now_ans);
        }
        val *= 2;
        index++;
    }
    cout << ans << endl;
    return 0;
}
