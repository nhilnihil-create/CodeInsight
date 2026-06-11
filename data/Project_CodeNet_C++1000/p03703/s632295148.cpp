#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

typedef pair<ll, int> P;

//struct BIT{
//    int N;
//    vector<int> data;
//
//    BIT(int n){
//        N = n;
//        data.resize(N+1, 0);
//    }
//
//    void add(int a, int w){
//        for(int x = a; x <= N; x += x & -x)
//            data[x] += w;
//    }
//
//    int sum(int a){
//        int ret = 0;
//        for(int x = a; x > 0; x -= x & -x)
//            ret += data[x];
//        return ret;
//    }
//
//};

struct BIT{
    int N;
    vector<int> data;

    BIT(int n){
        N = n;
        data.resize(N, 0);
    }

    // 0-indexed
    void add(int a, int w){
        for(int x = a; x < N; x |= x + 1)
            data[x] += w;
    }

    int sum(int a){
        int ret = 0;
        for(int x = a-1; x >= 0; x = (x & (x+1)) - 1)
            ret += data[x];
        return ret;
    }
};

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a - K;
    }

    vector<ll> S(N);
    S[0] = A[0];
    priority_queue<P, vector<P>, greater<P> > que;

    que.push(P(0, 0));
    que.push(P(S[0], 1));
    for(int i = 1; i < N; i++){
        S[i] = S[i-1] + A[i];
        que.push(P(S[i], i+1));
    }


    vector<int> X(N+1);
    REP(i,N+1){
        auto p = que.top(); que.pop();
        X[p.second] = i;
    }

    BIT bit(N+1);
    ll ans = 0;
    for(int i = 0; i < N+1; i++){
        int x = X[i];
        //ans += bit.sum(x+1);
        //bit.add(x+1, 1);
        ans += bit.sum(x);
        bit.add(x, 1);
    }

    cout << ans << endl;
    return 0;
}
