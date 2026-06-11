#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        vec.at(A - 1) = i;
    }
    ll ret = 0;
    multiset<int> ms{-1,N};
    for(ll i = 0;i < N;i++) {
        auto itr = ms.upper_bound(vec.at(i));
        ll A = *itr;
        --itr;
        ll B = *itr;
        ret += (i + 1) * (A - vec.at(i)) * (vec.at(i) - B);
        ms.insert(vec.at(i));
    }
    cout << ret << endl;
}