#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

int main() {
    ll  N;
    cin >> N;
    ll A, B;
    ll ans = MOD;
    for(int i = 1; i <= sqrt(N); i++){
        if(N % i == 0){
            A = i;
            B = N / i;
            ans = min(ans, ll(max(to_string(A).size(), to_string(B).size())));
        }
    }
    cout << ans << endl;
}
