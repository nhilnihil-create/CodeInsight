#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> x(N);
    set<ll> s;
    for (ll i = 0; i < N; i++) {
        cin >> a[i]; a[i]--;
        x[a[i]] = i;
    }

    s.insert(-1);
    s.insert(N);
    ll p, q;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        s.insert(x[i]);
        auto itr = s.find(x[i]);
        itr--;
        p = *itr;
        itr++; itr++;
        q = *itr;
        ans += (x[i] - p) * (q - x[i]) * (i+1);
        // printf("%lld %lld %lld\n", p, x[i], q);
    }

    printf("%lld\n", ans);


}