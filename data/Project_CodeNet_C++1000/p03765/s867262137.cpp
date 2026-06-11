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
  
  string s;
  string t;
  cin>>s;
  cin>>t;
  int n = s.size();
  int m = t.size();
  int sdsum[n];
  int tdsum[m];
  REP(i,n){
    if(i==0){
      if(s[i]=='A'){
        sdsum[i] = 1;
      }else{
        sdsum[i] = 2;
      }
    }else{
      if(s[i]=='A'){
        sdsum[i] = 1 + sdsum[i-1];
      }else{
        sdsum[i] = 2 + sdsum[i-1];
      }
    }
  }
  
  REP(i,m){
    if(i==0){
      if(t[i]=='A'){
        tdsum[i] = 1;
      }else{
        tdsum[i] = 2;
      }
    }else{
      if(t[i]=='A'){
        tdsum[i] = 1 + tdsum[i-1];
      }else{
        tdsum[i] = 2 + tdsum[i-1];
      }
    }
  }
  
  int q;
  cin>>q;
  int a,b,c,d;
  REP(i,q){
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    int from_, to_;
    if(a==0){
      from_ = sdsum[b];
    }else{
      from_ = sdsum[b] - sdsum[a-1];
    }
    if(c==0){
      to_ = tdsum[d];
    }else{
      to_ = tdsum[d] - tdsum[c-1];
    }
    if(from_%3 == to_%3){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
