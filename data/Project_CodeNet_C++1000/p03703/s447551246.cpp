#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MOD=1000000007;
int INF=100100100100100;

//ここから書く
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  //[0,i)の和
  T sum(int i) {
    i--;
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  //[l,r)の和
  T sum(int l, int r) {
    return sum(r) - sum(l);
  }
};

int tentou(ivec &v){
  int n=v.size();
  int res=0;
  BIT<int> b(n);
  rep(i,n){
    res+=i-b.sum(v[i]);
    b.add(v[i],1);
  }
  return res;
}
signed main(){
  int n,k;cin>>n>>k;
  ivec s(n+1);
  map<int,int> ma;
  rep(i,n){
    int x;cin>>x;
    x-=k;
    s[i+1]=s[i]+x;
  }
  ivec t=s;
  ivec po(n+1);
  sort(all(t));
  rep(i,n+1){
    po[i]=lower_bound(all(t),s[i])-t.begin();
    po[i]+=ma[s[i]];
    ma[s[i]]++;
  }
  cout<<n*(n+1)/2-tentou(po)<<endl;
  return 0;
}