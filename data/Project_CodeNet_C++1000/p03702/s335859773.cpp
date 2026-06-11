#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-9;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i > 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

ll n, A, B;
vector<ll> h;

bool check(ll x){
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if(h[i] <= B*x) continue;
        else cnt += (h[i]-B*x-1)/(A-B)+1;
    }
    return cnt <= x;
}

int main() {
    cin >> n >> A >> B;
    h.resize(n);
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h.begin(), h.end());

    ll ok = ll(1e9), ng = 0;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}
