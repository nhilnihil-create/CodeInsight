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
  
  int n;
  cin>>n;
  int a[n];
  int d = 0;
  int cnt[n] = {};
  REP(i,n){
    cin>>a[i];
    d = max(d, a[i]);
    cnt[a[i]]++;
  }
  
  bool flag = true;
  int temp;
  REP(i,d+1){
    temp = max(i,d-i);
    if(cnt[temp]){
      cnt[temp]--;
    }else{
      flag = false;
      break;
    }
  }
  if(!flag){
    cout<<"Impossible"<<endl;
    return 0;
  }
  
  int l,r;
  l = (d+1)/2+1;
  r = d;
  REP(i,n){
    if(cnt[i]){
      if(l<=i && i<=d){
        continue;
      }else{
        flag = false;
        break;
      }
    }
  }
  
  if(flag){
    cout<<"Possible"<<endl;
  }else{
    cout<<"Impossible"<<endl;
  }
  
  return 0;
}
