#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
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

ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        int A;
        cin >> A;
        A--;
        vec.at(i) = P(A,i + 1);
    }
    sort(vec.begin(),vec.end());
    vector<int> ret(N * N,-1);
    bool ret2 = true;
    for(int i = 0;i < N;i++) {
        ret.at(vec.at(i).first) = vec.at(i).second;
        int cnt = vec.at(i).second - 1;
        for(int j = 0;j < vec.at(i).first;j++) {
            if(cnt == 0) {
                break;
            }
            if(ret.at(j) == -1) {
                ret.at(j) = vec.at(i).second;
                cnt--;
            }
        }
        if(cnt != 0) {
            ret2 = false;
        }
    }
    reverse(vec.begin(),vec.end());
    for(int i = 0;i < N;i++) {
        ret.at(vec.at(i).first) = vec.at(i).second;
        int cnt = N - vec.at(i).second;
        for(int j = N * N - 1;j > vec.at(i).first;j--) {
            if(cnt == 0) {
                break;
            }
            if(ret.at(j) == -1) {
                ret.at(j) = vec.at(i).second;
                cnt--;
            }
        }
        if(cnt != 0) {
            ret2 = false;
        }
    }
    if(ret2 == false) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
        for(int i = 0;i < N * N;i++) {
            cout << ret.at(i) << " ";
        }
        cout << endl;
    }
}