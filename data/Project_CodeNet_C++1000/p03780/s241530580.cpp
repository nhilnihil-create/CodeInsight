#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N,K; cin >> N >> K;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    sort(a.begin(),a.end());
    int ng = -1,ok = N;
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        vector<int> v;
        rep(i,N){
            if(i != mid) v.push_back(a[i]);
        }
        bool dp[5000][5000];
        rep(i,5000)rep(j,5000) dp[i][j] = false;
        dp[0][0] = true;
        rep(i,N-1)rep(j,K){
            if(j-v[i] >= 0 && dp[i][j-v[i]]) dp[i+1][j] = true; 
            if(dp[i][j]) dp[i+1][j] = true;
        }
        bool flag = false;
        repr(i,max(K-a[mid],0),K){
            if(dp[N-1][i]) flag = true;
        }
        if(flag) ok = mid;
        else ng = mid; 
    }
    cout << ok << endl;
}

