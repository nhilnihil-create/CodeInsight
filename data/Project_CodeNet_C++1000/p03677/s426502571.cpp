#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int n,m;
int a[200010];
ll S[200010];

void solve(){
  cin >> n >> m;
  ll k=0;
  rep(i,n){
    cin >> a[i];
    if(i>=1)if(a[i]<a[i-1])k+=m;
  }
  //cout << a[0] << " " << a[n-1]+k << endl;
  rep(i,n-1){
    if(a[i]+1<a[i+1]){
      S[a[i]+1]+=1;
      S[a[i+1]]-=1;
    }
    else if(a[i]>a[i+1] && a[i]+1<a[i+1]+m){
      S[a[i]+1]+=1;
      S[a[i+1]+m]-=1;
    }
  }
  // rep(i,2*m){
  //   cout << S[i] << " ";
  // }
  // cout << "" << endl;
  rep(i,2*m-1){
    S[i+1]+=S[i];
  }
  rep(i,n-1){
    if(a[i]+1<a[i+1]){
      S[a[i+1]]-=a[i+1]-a[i]-1;
    }
    else if(a[i]>a[i+1] && a[i]+1<a[i+1]+m){
      S[a[i+1]+m]-=a[i+1]-a[i]+m-1;
    }
  }
  // rep(i,2*m){
  //   cout << S[i] << " ";
  // }
  // cout << "" << endl;
  rep(i,2*m-1){
    S[i+1]+=S[i];
  }
  // rep(i,2*m){
  //   cout << S[i] << " ";
  // }
  // cout << "" << endl;
  ll ans=0;
  rep(i,m){
    ans=max(S[i]+S[i+m],ans);
  }
  cout << (ll)a[n-1]+k-(ll)a[0]-ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}