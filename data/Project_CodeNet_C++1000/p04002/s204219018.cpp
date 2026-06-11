#include <bits/stdc++.h>
#define double long double
using namespace std;
const int N = 100010;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}


signed main(){
  ll h,w,n;
  cin>>h>>w>>n;

  map<int,map<int,int> > M;
  vector<int> A(n),B(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b; a--,b--;
    A[i] = a;
    B[i] = b;
    M[a][b] = 1;
  }
  
  map<int,map<int,int> > counted;
  auto count=[&](int y,int x){
    if(y < 0 || x < 0 || y + 2 >= h || x + 2 >= w) return 0;
    if(counted[y][x]++) return 0;

    int cnt = 0;
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++) cnt += M[y+i][x+j];
    return cnt;
  };

  
  vector<ll> ans(10);
  ans[0] = (w-2)*(h-2);
  for(int k=0;k<n;k++){
    int y = A[k];
    int x = B[k];
    for(int i=-2;i<=0;i++)
      for(int j=-2;j<=0;j++){
        int cnt = count(y+i,x+j);
        if(cnt) ans[0]--,ans[cnt]++;
      }
  }

  for(int i=0;i<10;i++) cout<<ans[i]<<endl;
  
  return 0;
}
