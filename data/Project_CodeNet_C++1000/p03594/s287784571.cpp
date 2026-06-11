#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)
#define Pr(a) (#a)<<"="<<(a)<<" "
#define pr1(a) cerr<<Pr(a)<<endl;
#define pr2(a,b) cerr<<Pr(a)<<Pr(b)<<endl;
#define pr3(a,b,c) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<endl;
#define pr4(a,b,c,d) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<endl;
#define pr5(a,b,c,d,e) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<endl;
#define pr6(a,b,c,d,e,f) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<Pr(f)<<endl;
#define int long long
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


int color[2000][2000];
signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  
  int h,w,d;
  cin>>h>>w>>d;
  vector<string> ans(h,string(w,'.'));

  char RYGB[]={'R','Y','G','B'};

  
  for(int i=0;i<2000;i++)
    for(int j=0;j<2000;j++) {
      int a = (i / d)%2;
      int b = (j / d)%2;
      color[i][j] = RYGB[2*a+b];
    }

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
      int u = i + j + 1000;
      int v = i - j + 1000;
      ans[i][j] = color[u][v];
    }

  for(int i=0;i<h;i++) cout<<ans[i]<<endl;


  
  return 0;
}
