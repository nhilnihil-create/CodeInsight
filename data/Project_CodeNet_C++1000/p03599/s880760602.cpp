#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  double a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  
  double dens=0,ww=0,ws=0;
  for(int i=0;100*a*i<=f;i++){
    for(int j=0;100*a*i+100*b*j<=f;j++){
      double w=100*a*i+100*b*j;
      for(int k=0;c*k+w<=f;k++){
        if(c*k>e*w/100)continue;
        for(int l=0;c*k+d*l+w<=f;l++){
          double s=c*k+d*l;
          if(s>e*w/100)continue;
          if(dens<100*s/(s+w)){
            dens=100*s/(s+w);
            ww=w;
            ws=s;
          }            
        }
      }
    }
  }
  if(ww==0)cout << 100*a << " " <<0<<endl;
  else cout << ww+ws << " " <<ws << endl;
          
}
