#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
template<typename T>
T RS(T N, T P, T M){
    if(P==0) return 1;
    if(P < 0) return 0;
    if(P%2==0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) return N * RS(N,P - 1,M);
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<vector<int>> cnt(M);
    for(int i = 0;i < N;i++) {
        cnt.at(vec.at(i) % M).push_back(vec.at(i));
    }
    vector<P> cnt2(M); //first:総数、second:奇数個ある数
    for(int i = 0;i < M;i++) {
        sort(cnt.at(i).begin(),cnt.at(i).end());
        cnt2.at(i).first = cnt.at(i).size();
        int odd = 0;
        int cnt3 = 0;
        int count = 0;
        for(int j = 0;j < cnt.at(i).size();j++) {
            if(cnt.at(i).at(j) != cnt3) {
                if(count % 2 == 1) {
                    odd++;
                }
                cnt3 = cnt.at(i).at(j);
                count = 1;
            }
            else {
                count++;
            }
        }
        if(count % 2 == 1) {
            odd++;
        }
        cnt2.at(i).second = odd;
    }
    int ret = 0;
    ret += cnt2.at(0).first / 2;
    for(int i = 1;i <= M / 2;i++) {
        if(i == M - i) {
            ret += cnt2.at(i).first / 2;
        }
        else {
            P A = cnt2.at(i);
            P B = cnt2.at(M - i);
            int cnt5 = min(A.second, B.second);
            ret += cnt5;
            A.first -= cnt5;
            A.second -= cnt5;
            B.first -= cnt5;
            B.second -= cnt5;
            if(A.second != 0) {
                int cnt6 = min(A.second, B.first);
                ret += cnt6;
                A.first -= cnt6;
                A.second -= cnt6;
                B.first -= cnt6;
            }
            else if(B.second != 0) {
                int cnt6 = min(A.first, B.second);
                ret += cnt6;
                A.first -= cnt6;
                B.first -= cnt6;
                B.second -= cnt6;
            }
            ret += (A.first - A.second) / 2 + (B.first - B.second) / 2;
        }
    }
    cout << ret << endl;
}