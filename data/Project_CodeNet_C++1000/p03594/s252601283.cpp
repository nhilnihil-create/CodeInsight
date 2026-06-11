#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>
#include<stack>
#include<tuple>
#include<numeric>
#include<cassert>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back
#define DEBUG false

using namespace std;

using ll = long long;
using P = pair<int,int>;

const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll LINF=1LL<<60;
const int MAX_N=2003;
const ll lmod = 1e9+7;

int c[MAX_N][MAX_N],ch[MAX_N][MAX_N];

int main(){
  int h,w,d;
  cin >> h >> w >> d ;
  rep(i,MAX_N) ch[0][i] = (i%2);
  REP(i,1,MAX_N){
    rep(j,MAX_N){
      ch[i][j] = (ch[i-1][j]+2)%4;
      // cout << ch[i][j] << ",";
    }
    // cout << "" << endl;
  }
  string s = "RGYB";
  rep(i,h) rep(j,w) c[i][j] = ch[(i+j)/(d)][(i-j+1000*d)/(d)];
  rep(i,h){
    rep(j,w) cout << s[c[i][j]];
    cout << endl;
  }
  // rep(i,h){
  //   rep(j,w) cout <<  (i+j)/(d) << "," << (i-j+10*d)/d << " ";
  //   cout << "" << endl;
  // }
  
  return 0;
}