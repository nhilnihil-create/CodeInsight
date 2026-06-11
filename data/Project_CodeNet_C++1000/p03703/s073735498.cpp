#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
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

// Binary Indexed Tree (Fenwick Tree)
template<typename T> // T: type of cost
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
};

int main(){
  
  int n;
  long long k;
  cin>>n>>k;
  long long a[n];
  REP(i,n){
    cin>>a[i];
    a[i] -= k;
  }
  vector<long long> s(n+1,0);
  REP(i,n+1){
    if(i==0)continue;
    s[i] = s[i-1] + a[i-1];
  }
  //各iについてj<iかつs[j]<=s[i]となるjの個数を知りたい。
  
  vector<long long> temps(n+1);
  REP(i,n+1){
    temps[i] = s[i];
  }
  //sの値を座標圧縮
  sort(temps.begin(),temps.end());
  temps.erase(unique(temps.begin(),temps.end()),temps.end());
  map<long long, int> zip;
  for(int i = 0; i < temps.size(); i++){
        zip[temps[i]] = i;
  }
  
  int MAP = temps.size();
  BIT<int> bit(MAP);
  long long ans = 0;
  REP(i,n+1){
    ans += (long long)bit.sum(zip[s[i]]);
    bit.add(zip[s[i]]);
  }
  cout<<ans<<endl;
  return 0;
}
