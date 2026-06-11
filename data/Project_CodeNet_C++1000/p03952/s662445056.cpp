#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000010;
constexpr ll INF= 1000000000000000000;
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

ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P < 0) {
        return 0;
    }
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N,x;
    cin >> N >> x;
    if(x == 1 || x == 2 * N - 1) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        if(N == 2) {
            cout << 1 << endl << 2 << endl << 3 << endl;
            return 0;
        }
        vector<bool> used(2 * N - 1);
        vector<int> ret(2 * N - 1);
        if(x == 2) {
            ret.at(N - 2) = 3;
            ret.at(N - 1) = 2;
            ret.at(N) = 1;
            ret.at(N + 1) = 4;
            used.at(0) = true;
            used.at(1) = true;
            used.at(2) = true;
            used.at(3) = true;
        }
        else {
            ret.at(N - 2) = x - 1;
            ret.at(N - 1) = x;
            ret.at(N) = x + 1;
            ret.at(N + 1) = x - 2;
            used.at(x - 3) = true;
            used.at(x - 2) = true;
            used.at(x - 1) = true;
            used.at(x) = true;
        }
        int itr = 0;
        for(int i = 0;i < 2 * N - 1;i++) {
            if(ret.at(i) == 0) {
                while(true) {
                    if(used.at(itr) == false) {
                        ret.at(i) = itr + 1;
                        used.at(itr) = true;
                        break;
                    }
                    itr++;
                }
            }
        }
        for(int i = 0;i < 2 * N - 1;i++) {
            cout << ret.at(i) << endl;
        }
    }
}