#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,k;
  cin >> n >> k;
  ll a[n];
  rep(i,n){
    cin >> a[i];
    a[i]-=k;
  }
  ll sum[n+1];
  multiset<ll> ms;
  vector<pair<ll,ll>> v;
  sum[0]=0;
  //  ms.insert(0);
  v.pb(mp(0,0));
  rep(i,n){
    sum[i+1] = sum[i]+a[i];
    //    ms.insert(sum[i+1]);
    v.pb(mp(sum[i+1],i+1));
  }
  BinaryIndexedTree< ll > bit(n+1);
  sort(v.begin(),v.end());
  ll ans=0; //左側を見るときは小さいのを　右のときは大きいのを探す
  rep(i,n+1){
    int pos=v[i].second;
    ans += bit.sum(pos);
    bit.add(pos,1);
    //    hans += v.end() - upper_bound(v.begin(), v.end(),sum[i]);
    //    eans += upper_bound(v.begin(), v.end(),sum[i]) - lower_bound(v.begin(), v.end(),sum[i]);
    //    if(i==0) ans--;
  }
  cout << ans << endl;
  
  return 0;
    

}
