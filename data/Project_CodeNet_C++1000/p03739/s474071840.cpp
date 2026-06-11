#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 2e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
 
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
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    ll sum = 0;
    ll ret1 = 0;
    ll ret2 = 0;
    for(int i = 0;i < N;i++) {
        sum += vec.at(i);
        if(i % 2 == 0) {
            if(sum <= 0) {
                ret1 += 1 - sum;
                sum = 1;
            }
        }
        else {
            if(sum >= 0) {
                ret1 += sum + 1;
                sum = -1;
            }
        }
    }
    sum = 0;
    for(int i = 0;i < N;i++) {
        sum += vec.at(i);
        if(i % 2 == 0) {
            if(sum >= 0) {
                ret2 += sum + 1;
                sum = -1;
            }
        }
        else {
            if(sum <= 0) {
                ret2 += 1 - sum;
                sum = 1;
            }
        }
    }
    cout << min(ret1,ret2) << endl;
}