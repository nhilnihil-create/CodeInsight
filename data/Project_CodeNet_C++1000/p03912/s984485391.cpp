#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int func(int a, int b){
    return (a+b)/2;
}

int func(int a0, int b0, int a1, int b1){
    if(b0 < b1){
        swap(a0, a1);
        swap(b0, b1);
    }
    int ans = min(b0, a1+b1);
    a1 = max(0, a1 - (b0-b1));
    ans += a0/2;
    ans += a1/2;
    return ans;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    REP(i, N) cin >> X[i];
    map<int, int> mp;
    REP(i, N) mp[X[i]]++;

    vector<int> A(M), B(M);
    for(auto x : mp){
        int num = x.first % M;
        int rem = x.second % 2;
        A[num] += x.second - rem;
        B[num] += rem;
    }
    int ans = 0;
    REP(i, M/2+1){
        int j = (M - i) % M;
        if(i == j) ans += func(A[i], B[i]);
        else ans += func(A[i], B[i], A[j], B[j]);
    }
    cout << ans << endl;
    return 0;
}
