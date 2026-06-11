#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  ll n;
  cin >> n;
  vector<ll>a(n);
  rep(i,n) cin >> a[i];
  
  ll sum1=0,res1=0;
  rep(i,n){
    sum1+=a[i];
    if(i%2==0){
      if(sum1>=0){
        res1+=abs(sum1)+1;
        sum1=-1;
      }
    }
    else{
      if(sum1<=0){
        res1+=abs(sum1)+1;
        sum1=1;
      }
    }
  }
  ll sum2=0,res2=0;
  rep(i,n){
    sum2+=a[i];
    if(i%2==0){
      if(sum2<=0){
        res2+=abs(sum2)+1;
        sum2=1;
      }
    }
    else{
      if(sum2>=0){
        res2+=abs(sum2)+1;
        sum2=-1;
      }
    }
  }
  cout << min(res1,res2 ) << endl;
  return 0;
}
