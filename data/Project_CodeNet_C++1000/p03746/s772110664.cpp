#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2100000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void mod(ll &val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> graph[N];
    int start,last;
    for(int i = 0;i < M;i++) {
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        if(i == 0) {
            start = A;
            last = B;
        }
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    vector<bool> used(N);
    deque<int> que;
    que.push_front(start);
    que.push_back(last);
    used.at(start) = true;
    used.at(last) = true;
    while(true) {
        bool ret = false;
        for(auto x:graph[start]) {
            if(!used.at(x)) {
                start = x;
                que.push_front(x);
                used.at(x) = true;
                ret = true;
                break;
            }
        }
        for(auto x:graph[last]) {
            if(!used.at(x)) {
                last = x;
                que.push_back(x);
                used.at(x) = true;
                ret = true;
                break;
            }
        }
        if(ret == false) {
            break;
        }
    }
    cout << que.size() << endl;
    for(auto x:que) {
        cout << x + 1 << " ";
    }
    cout << endl;
}