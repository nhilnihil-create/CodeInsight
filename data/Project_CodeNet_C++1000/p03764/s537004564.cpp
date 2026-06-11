#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int mod = 1000000007;
int esum(vec x){
    int N = x.size();
    int s = 0;
    vec c(N + 1, 0);
    REP(i, N) c[i + 1] = c[i] + x[i];
    REP(i, N){
        s += c[N] - c[i] - (N - i) * x[i];
        s %= mod; 
    }
    return s;
}

signed main(){

    int n, m; cin >> n >> m;
    vec x(n), y(m);
    readvec(x); readvec(y);

    cout << (esum(x) * esum(y)) % mod;
    
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