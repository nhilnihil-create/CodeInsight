#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int cnt2=0;
  int cnt4=0;
  rep(i,n){
    if(a[i]%4==0) cnt4++;
    else if(a[i]%2==0) cnt2++;
  }
  int N=cnt4*2+cnt2;
  if(cnt2==0) N=cnt4*2+1;
  if(N>=n){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  
}