#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define INF 999999999
using namespace std;

int main(){
          int h,w;
          cin >> h >> w;
          string s[h][w];
          REP(i,h)  REP(j,w)  cin >> s[i][j];
          REP(i,h)  REP(j,w){
                    if(s[i][j]=="snuke"){
                              cout << char(j+'A') <<  i+1 << endl;
                    }
          }
          return 0;
}
