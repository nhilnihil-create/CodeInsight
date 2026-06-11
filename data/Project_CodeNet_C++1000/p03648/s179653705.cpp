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

void process(vec &a, int N){
    int imax, m = -1;
    REP(i, N){
        if(a[i] > m){
            m = a[i];
            imax = i;
        }
    }
    a[imax] -= (N + 1);
    REP(i, N) a[i]++;
}

signed main(){

    int K; cin >> K;
    if(K == 0){
        cout << 2 << endl;
        cout << 0 << " " << 0;
        return 0;
    }
    int N = 50;
    int a = K / N + min((int)1, K % N);
    int b = a * N - K;
    vec ans(N);
    REP(i, N) ans[i] = i + a;
    REP(i, b) process(ans, N);

    cout << N << endl;
    REP(i, N) cout << ans[i] << " ";
    
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