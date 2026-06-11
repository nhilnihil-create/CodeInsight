#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N, A, B; cin >> N >> A >> B;
    vec h(N); readvec(h);
    A -= B;

    int ans1 = 0, ans2 = 1000000000;
    while(ans2 - ans1 > 1){
        int ans = (ans1 + ans2 + 1) / 2;
        int n = 0;
        REP(i, N) if(h[i] > B * ans) n += (h[i] - B * ans) / A + min(1LL, (h[i] - B * ans) % A);
        if(n <= ans) ans2 = ans; else ans1 = ans;
    }

    cout << ans2;
    
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