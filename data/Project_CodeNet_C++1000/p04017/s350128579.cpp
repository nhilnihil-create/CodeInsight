#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
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
using namespace std;
//using namespace boost::multiprecision;

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
  
  int n;
  cin>>n;
  int x[n];
  REP(i,n){
    cin>>x[i];
  }
  int L;
  cin>>L;
  int s[n][31];
  REP(i,n){
    int l = i, r = n;//[l,r)
    while(r - l > 1){
      int m = (l+r)/2;
      if(x[m] - x[i] <= L){
        l = m;
      }else{
        r = m;
      }
    }
    s[i][0] = l;
  }
  REP(k,31){
    REP(i,n){
      if(k == 0)continue;
      s[i][k] = s[s[i][k-1]][k-1];
    }
  }
  int q;
  cin>>q;
  int a[q],b[q];
  REP(i,q){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    if(a[i] > b[i]){
      swap(a[i], b[i]);
    }
  }
  int ans[q];
  REP(i,q){
    int l = 0, r = 1e9 + 10;//(l,r]
    while(r - l > 1){
      int d = (l+r)/2;
      int now = a[i];
      REP(k,31){
        if(d & (1<<k)){
          now = s[now][k];
        }
      }
      if(now >= b[i]){
        r = d;
      }else{
        l = d;
      }
    }
    ans[i] = l;
  }
  REP(i,q){
    cout<<ans[i] + 1<<endl;
  }
  return 0; 
}