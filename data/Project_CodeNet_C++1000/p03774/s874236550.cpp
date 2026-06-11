#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


  








int main() {
  int n,m;
  cin >> n >> m;
  ll a[n+1],b[n+1],c[m+1],d[m+1];
  rep (i,n){
    cin >> a[i] >> b[i];
  }
  rep (i,m){
    cin >> c[i] >> d[i];
  }
  rep (i,n){
    ll mini=INF,ans=-1;
    rep (j,m){
    ll dis = abs(a[i]-c[j])+abs(b[i]-d[j]);
    if (mini>dis){
     // cout << a[i] << " " << c[j] << " " << b[i] << " " << d[i] << endl;
    mini = min(dis,mini);
    ans = j+1;
    //cout << dis << endl;
    }
    }
    cout << ans << endl;
    //cout << endl;
  }
}