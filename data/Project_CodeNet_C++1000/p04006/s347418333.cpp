#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> v(N);
    for (ll i = 0; i < N; i++) {
        v[i] = A[i];
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += v[i];
    }
    ll tmp;
    for (ll k = 1; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            v[i] = min(v[i], A[(i-k+N) % N]);
        }
        tmp = 0;
        for (ll i = 0; i < N; i++) {
            tmp += v[i];
        }
        ans = min(ans, tmp + k * X);
    }
    printf("%lld\n", ans);

}