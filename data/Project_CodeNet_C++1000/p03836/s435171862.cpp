#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
 
int main()
{
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int difx = tx-sx;
  int dify = ty-sy;
  REP(i,difx){
    cout << "R";
  }
  REP(i,dify){
    cout << "U";
  }
  REP(i,difx){
    cout << "L";
  }
  REP(i,dify){
    cout << "D";
  }
  cout << "D";
  REP(i,difx+1){
    cout << "R";
  }
  REP(i,dify+1){
    cout << "U";
  }
  cout << "L";
  cout << "U";
  REP(i,difx+1){
    cout << "L";
  }
  REP(i,dify+1){
    cout << "D";
  }
  cout << "R" << endl;
}