#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

template <typename T>
class BIT{
  vector<T> array;
  int n;
public:
  BIT(int num){
    n = num;
    array.resize(n + 1);
  }
  T sum(int i){
    T s = 0;
    while(i > 0){
      s += array[i];
      i -= i & -i;
    }
    return s;
  }
  T sum(int i, int j){
    return sum(j)-sum(i-1);
  }
  void add(int i, T x){
    while(i <= n){
      array[i] += x;
      i += i & -i;
    }
  }
};

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);

  rep(i,n){
    cin>>a[i];
    a[i]-=k;
  }

  //累積和
  vector<ll>S(n+1);
  for(int i=1; i<=n; ++i){
    S[i]=S[i-1]+a[i-1];
  }
  
  //座標圧縮
  map<ll,int>mp;
  rep(i,n+1)mp[S[i]]++;
  int cnt=1;
  for(auto &p:mp){
    p.second=cnt;
    cnt++;
  }
  rep(i,n+1){
    S[i]=mp[S[i]];
  }

  ll ans=(ll)n*(n+1)/2;
  BIT<int>bit(n+1);
  rep(i,n+1){
    bit.add(S[i],1);
    ans-=bit.sum(n+1)-bit.sum(S[i]);
  }
  cout<<ans<<endl;
}