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
  
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  if(H%h == 0 && W%w == 0){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  int ans[H][W];
  if(H%h != 0){
    REP(i,H){
      int temp;
      if(i%h == 0){
        temp = 1000*h - 1001;
      }else{
        temp = -1000;
      }
      REP(j,W){
        ans[i][j] = temp;
      }
    }
  }else{
    REP(j,W){
      int temp;
      if(j%w == 0){
        temp = 1000*w - 1001;
      }else{
        temp = -1000;
      }
      REP(i,H){
        ans[i][j] = temp;
      }
    }
  }
  
  REP(i,H){
    REP(j,W){
      cout<<ans[i][j]<<' ';
    }
    cout<<endl;
  }
      
  return 0;
}
