#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int main(){
  ll n;cin>>n;
  ll er=n*(n+1)/2;
  ll sum=0;
  vector<ll> a(n),c(n);
  bool can=true;
  for(int i=0;i<n;i++){
      cin>>a[i];
      sum+=a[i];
  }
  if(sum%er!=0){
      cout<<"NO"<<endl;
      return 0;
  }
  //操作回数を決める
  ll times=sum/er;
  //区間の差を求める
  for(int i=0;i<n;i++)c[i]=a[(i+1)%n]-a[i]-times;
//区間は操作のたびに一つがn-1足されそれ以外が-1される
//つまり区間の差に操作回数を引いたものがn-1足されているのを除いたものである
//-1余分に引かれていることを考慮するとその値はnの倍数になることがわかる
//なぜなら用意した区間はちょうど0になる必要があるからだ
  for(int i=0;i<n;i++){
      if(c[i]>0)can=false;
      if(c[i]%n!=0)can=false;
  }
  if(can)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
  
