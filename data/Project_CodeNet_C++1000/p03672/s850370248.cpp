#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  string s;
  cin >> s;
  int n = s.size();
  string t;
  int len = 1;
  int mxlen = 0;


while(len <= n/2-1){
  //cout << len << endl;
  bool ok = true;
  for(int i = 0; i < len ; i++){
      if(s[i] != s[i+len]) {
        ok = false;
        break;
      }
    }
   if(ok) mxlen = len*2;
   len++;
 }

  cout << mxlen << endl;


  return 0;
}
