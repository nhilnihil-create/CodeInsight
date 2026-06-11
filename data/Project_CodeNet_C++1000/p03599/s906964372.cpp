#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;

  double MAX = -INF;
  int answ = 0;
  int anss = 0;
  REP(i,31){
    int water = i*100;
    REP(j,i*E+1){
      int sugar = j;
      if(water+sugar>F) break;
      //Ax+By=i Cz+Dw=j
      int flag = 0;
      REP(k,i/A+2){
        if((i-A*k)%B==0&&(i-A*k)/B>=0){
          flag=1;
        }
      }
      int flag2 = 0;
      REP(k,j/C+2){
        if((j-C*k)%D==0&&(j-C*k)/D>=0){
          flag2=1;
        }
      }
      if(flag==1&&flag2==1){
        if(MAX*(i+j)<j){
          double z = i+j;
          MAX = j/z;
          answ = i*100;
          anss = j;
        }
      }
    }
  }

  cout << answ+anss << " " << anss << endl;
} 