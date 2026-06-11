
    // Your code here!
    #include <bits/stdc++.h>
 
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
typedef long long ll;
//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main(){
  ll n,ans=0;
  cin>>n;
  vll a(3*n);
  rep(i,3*n)cin>>a.at(i);
  sort(ALL(a));
  ll k=0;
  for(ll i=3*n-2;k<n;i-=2){
      ans+=a.at(i);
      k++;
  }
  cout<<ans<<endl;
}

   
    

   

