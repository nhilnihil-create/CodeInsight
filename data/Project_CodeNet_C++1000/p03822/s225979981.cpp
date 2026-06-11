#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}
 
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=std::sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}
 
long long gcd_(long long a, long long b){
  if(a<b){
    std::swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}
 
using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

vector<int> G[100'010];

int dfs(int v, vector<int>& dp, int p = -1){
  
  if(dp[v] >= 0) return dp[v];
  
  int deg = G[v].size();
  if(v != 0 && deg == 1) return dp[v] = 0;
  vector<int> temp;
  for(int nv: G[v]){
    if(nv == p) continue;
    temp.push_back(dfs(nv, dp, v));
  }
  sort(ALL(temp), greater<int>());
  int res = -1;
  int k = temp.size();
  REP(i, k) res = max(res, temp[i] + i + 1);
  return dp[v] = res;
}

int main(){
  //using namespace std;
  int n;
  cin>>n;
  int a[n];
  for(int i = 1; i < n; i++){
    cin>>a[i];
    a[i]--;
  }
  
  for(int i = 1; i < n; i++){
    G[i].push_back(a[i]);
    G[a[i]].push_back(i);
  }
  
  vector<int> dp(n, -1);
  dfs(0, dp);
  int ans = dp[0];
  cout << ans << endl;  
  return 0;
}
