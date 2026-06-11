#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    vector<ll> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    ll L;
    cin >> L;
    int K = 1;
    while((1<<K) < N) K++;
    vector<vector<int>> dbl(K, vector<int> (N));

    for (int i = 0; i < N; i++) {
        dbl[0][i] = (upper_bound(ALL(x), x[i] + L) - x.begin()) - 1;
    }

    for (int k = 1; k < K; k++) {
        for (int i = 0; i < N; i++) {
            dbl[k][i] = dbl[k-1][dbl[k-1][i]];
        }
    }

    int Q;
    cin >> Q;
    int a, b;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        ll ans = 0;
        for (int k = K-1; k >= 0; k--) {
            if(dbl[k][a] < b){
                a = dbl[k][a];
                ans += (1<<k);
            }
        }
        printf("%lld\n", ans + 1);
    }

}