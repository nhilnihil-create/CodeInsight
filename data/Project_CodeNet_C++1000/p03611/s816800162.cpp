#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  int ans=0;
  int tmp;
  
  rep(i,n){cin>>a[i];}
  sort(all(a));
  vector<int>cnt(100001);
  rep(i,n){cnt[a[i]]++;}
  tmp=0;
  Rep(i,1,cnt.size()-1){
    tmp=cnt[i-1]+cnt[i]+cnt[i+1];
    ans=max(tmp,ans);
  }
  
  cout<<ans<<endl;
  
    
    
  return 0;
}
