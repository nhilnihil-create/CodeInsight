#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
const double PI = acos(-1);
const double EPS = 1e-15;
long long INF=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}

long long gcd_(long long a, long long b){
  if(a<b){
    swap(a,b);
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

int main(){
  
  int n,a,b;
  cin>>n>>a>>b;
  vector<long long> v(n);
  REP(i,n){
    cin>>v[i];
  }
  sort(ALL(v), greater<long long>());
  double max_v = 0.0;
  REP(i,a){
    max_v += (double)v[i];
  }
  max_v /= (double)a;
  cout<<fixed<<setprecision(7)<<max_v<<endl;
  
  //二項係数を作っておく
  long long dp[n+1][n+1];
  dp[0][0] = 1;
  REPP(i,n){
    REP(j,i+1){
      if(j==0 || j==i){
        dp[i][j] = 1;
      }else{
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
      }
    }
  }
  
  //a番目の値と一致するv[i]の数
  int cnt = 0;
  REP(i,n){
    if(v[i]==v[a-1]){
      cnt++;
    }
  }
  //a番目の値と一致する 0<=i<=a-1 && v[i]の数
  int temp = 0;
  REP(i,a){
    if(v[i]==v[a-1]){
      temp++;
    }
  }
  long long ans = 0;
  int choose_num;
  if(v[0]==v[a-1]){
    for(int i = a;i<=b;i++){
      if(i>cnt)break;
      ans += dp[cnt][i];
    }
  }else{
    ans = dp[cnt][temp];
  }
  cout<<ans<<endl;
  return 0;
}