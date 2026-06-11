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



signed main(){

    int n; cin >> n;
    int mod = 1000000007;

    //i個を1個または3個に分割するやり方
    vec dp(n);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    int dpsum = dp[0] + dp[1] + dp[2];
    FOR(i, 3, n){
        dp[i] = (dpsum - dp[i - 2] + mod) % mod;
        dpsum = (dpsum + dp[i]) % mod;
    }

    int ans = 0;
    REP(i, n){
        //i+1項目から考える
        //i+i項目がn-i以上
        int tmp;
        if(i == n - 1) tmp = n;
        else if(i == n - 2) tmp = n - 1;
        else tmp = i + 2;
        if(i != n - 1) tmp = (tmp * n) % mod;
        if(i < n - 2){
            tmp += (n - 3 - i) * (n - 1);
            tmp %= mod;
        }
        ans += tmp * dp[i];
        ans %= mod;
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