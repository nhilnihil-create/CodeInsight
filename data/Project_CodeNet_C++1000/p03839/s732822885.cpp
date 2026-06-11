#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,K;
    cin >> N >> K;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<ll> Sum(N + 1);
    for(int i = 0;i < N;i++) {
        Sum.at(i + 1) = Sum.at(i) + vec.at(i);
    }
    vector<ll> positive(N + 1);
    for(int i = 0;i < N;i++) {
        if(vec.at(i) >= 0) {
            positive.at(i + 1) = positive.at(i) + vec.at(i);
        }
        else {
            positive.at(i + 1) = positive.at(i);
        }
    }
    ll ret = 0;
    for(int i = 0;i < N - K + 1;i++) {
        ll Sum2 = Sum.at(i + K) - Sum.at(i);
        ll p = positive.at(N) - positive.at(i + K) + positive.at(i);
        ret = max(ret,max(p,p + Sum2));
    }
    cout << ret << endl;
}