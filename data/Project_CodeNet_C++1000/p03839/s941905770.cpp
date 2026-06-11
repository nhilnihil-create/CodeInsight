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
  
  int n,k;
  cin>>n>>k;
  long long a[n];
  REP(i,n){
    cin>>a[i];
  }
  long long s[n],ps[n];
  REP(i,n){
    if(i==0){
      s[i] = a[i];
      ps[i] = max(0LL,a[i]);
    }else{
      s[i] = s[i-1] + a[i];
      ps[i] = ps[i-1] + max(0LL,a[i]);
    }
  }
  
  long long ans = 0;
  long long mid;
  long long temp;
  REP(i,n-k+1){
    if(i==0){
      mid = max(0LL,s[i+k-1]);
    }else{
      mid = max(0LL,s[i+k-1]-s[i-1]);
    }
    temp = mid;
    
    if(i==0){
      ;
    }else{
      temp += ps[i-1];
    }
    
    temp += ps[n-1] - ps[i+k-1];
    ans = max(ans,temp);
  }
  
  cout<<ans<<endl;
  return 0;
}
