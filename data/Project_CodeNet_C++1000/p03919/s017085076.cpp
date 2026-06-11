#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

//--------------------------------------------
const double EPS = 1e-14;
const double PI  = acos(-1.0);

//--------------------------------------------

int main(){
  int h,w;
  string s;
  vector <string> v;

  scanf("%d %d",&h,&w);

  char ansx;
  int ansy;
  FOR (i, 1, h + 1) {
    FOR (j, 1, w + 1) {
      cin >> s;
      if (s == "snuke") {
        ansx = j + 64;
        ansy = i;
      }
    }
  }

  printf("%c%d\n",ansx, ansy);
}
