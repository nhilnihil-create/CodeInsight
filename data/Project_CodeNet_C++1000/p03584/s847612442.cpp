#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int calcmax(vec &A, vec &B, int K){
    int ans = 0;
    REP(i, A.size()) if((A[i] | K) == K) ans += B[i];
    return ans;
}

signed main(){

    int N, K; cin >> N >> K;
    vec A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    int ans = calcmax(A, B, K);
    REP(i, 32){
        if((K >> i) % 2 == 0) continue;
        int k = (K >> (i + 1)) << (i + 1);
        k += (1 << i) - 1;
        ans = max(ans, calcmax(A, B, k));
    }
    cout << ans;
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}