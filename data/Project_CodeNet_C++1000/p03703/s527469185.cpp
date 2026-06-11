#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

// 1-indexedのBIT
struct BIT {
    vector<int> array;
    const int N;

    // 0として初期化
    BIT(int _N) : array(_N + 1, 0), N(_N) {}

    // 左からi番目にxを加える
    void add(int i, int x){
        int lsb;
        while(i <= N){
            array[i] += x;
            lsb = i & (-i);
            i += lsb;
        }
    }

    //左からi番目までのSUMを得る
    int getSUM1(int i){
        int ret = 0;
        int lsb;
        while(i >= 1){
            ret += array[i];
            lsb = i & (-i);
            i -= lsb;
        }
        return ret;
    }

    //左からi番目からj番目のSUMを得る
    int getSUM(int i, int j){
        return getSUM1(j) - getSUM1(i-1);
    }
};

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
        a[i] = a[i] - K;
    }

    vector<ll> s(N+1);
    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i+1] = s[i] + a[i];
    }

    map<ll, int> m;
    for (int i = 0; i < N+1; i++) {
        m[s[i]] = 1;
    }
    int ind = 1;
    for (auto v : m) {
        m[v.first] = ind;
        ind++;
    }
    for (int i = 0; i < N+1; i++) {
        s[i] = m[s[i]];
    }

    BIT bit(N+1);
    ll ans = 0;
    for (int i = 0; i < N+1; i++) {
        ans += bit.getSUM1(s[i]);
        bit.add(s[i], 1);
    }
    printf("%lld\n", ans);
}