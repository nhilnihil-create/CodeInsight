#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
ll a[100500];
ll sum;
int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    bool FIRST_WIN = true;
    while(true) {
        if(sum % 2 != N % 2) break;
        FIRST_WIN = !FIRST_WIN;
        int index = -1;
        for(int i = 1; i <= N; i++) {
            if(a[i] % 2 == 1) {
                if(index != -1) goto outer;
                index = i;
            }
        }
        a[index]--;
        if(a[index] == 0) break;
        ll GCD = a[1];
        for(int i = 2; i <= N; i++) {
            GCD = __gcd(GCD, a[i]);
        }
        for(int i = 1; i <= N; i++) {
            a[i] = a[i] / GCD;
        }
        sum = (sum - 1) / GCD;
    }
    outer:
    if(FIRST_WIN) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
