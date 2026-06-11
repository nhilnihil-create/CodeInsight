#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int n,ma,mb;
vector<int> A,B,C;
v2<vector<int>> dp;

const int INF = 1e9;

int f(int index, int a, int b){
    if(a<0 || b<0) return INF;
    if(index==-1){
        if(a==0 && b==0) return 0;
        else return INF;
    }
    if(dp[index][a][b] != -1) return dp[index][a][b];

    dp[index][a][b] = min(f(index-1, a, b), C[index]+f(index-1, a-A[index], b-B[index]));
    if(dp[index][a][b] > INF) dp[index][a][b] = INF;
    return dp[index][a][b];
}

void solve(){
    cin>>n>>ma>>mb;
    A = vector<int>(n), B = vector<int>(n), C = vector<int>(n);
    for(int i = 0; i < n; ++i) cin >> A[i] >> B[i] >> C[i];
    
    dp = fill(n, 10*n+1, vector<int>(10*n+1, -1));

    int ans = INF;
    for(int i = 1; ma*i<=10*n && mb*i<=10*n; ++i){
        ans = min(ans, f(n-1, ma*i, mb*i));
    }

    if(ans==INF) cout << "-1\n";
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}