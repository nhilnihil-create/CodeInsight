#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,n) for(int i=0;i<=n;i++)
#define repr(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
#define vector2(a,b,c) vector<vector<string>> a(b,vector<string>(c))
#define INF 1e10
#define MOD 1e9+7
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
signed main(){
  int a,b;
  cin>>a>>b;
  string c[30][30];
  rep(i,a)rep(j,b)
    cin>>c[i][j];
  int d;
  int e;
  rep(i,a)rep(j,b){
  if(c[i][j]=="snuke"){
    d=i+1;
    e=j+1;
    }
  }
  char f=e+64;
  cout<<f<<d<<endl;
}