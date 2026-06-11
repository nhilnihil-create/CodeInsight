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
  vector<int>a(9);
  int tmp;
  rep(i,n){
    cin>>tmp;
    if(tmp>=3200)a[8]++;
    else a[tmp/400]++;
  }
  int mi=0;
  int ma=0;
  int r=0;
  rep(i,8){
    if(a[i]!=0)mi++;
  }
  r=8-mi;
  ma=mi+a[8];

  mi=max(1,mi);
  cout<<mi<<" "<<ma<<endl;
    
    
  return 0;
}
