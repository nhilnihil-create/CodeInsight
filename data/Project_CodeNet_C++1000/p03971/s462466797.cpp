#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)    for (int i=(a)  ;i<(b) ;i++)
#define RFOR(i,a,b)   for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)      for (int i=0    ;i<(n) ;i++)
#define RREP(i,n)     for (int i=(n)-1;i>=0  ;i--)
#define EACH(i,a,b)   for (int i=(a)  ;i<=(b);i++)
#define REACH(i,a,b)  for (int i=(b)  ;i>=(a);i--)
#define ALL(a)        (a).begin(),  (a).end()
#define RALL(a)       (a).rbegin(), (a).rend()

const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const double EPS = 1e-10;

using ll = long long;
using P = pair<int,int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,A,B;
  cin >> N >> A >> B;
  string S;
  cin >> S;

  int a = 0;
  int b = 0;
  REP(i,N) {
    if (a + b >= A + B) {
      cout << "No" << endl;
    } else if (S[i] == 'a') {
      a += 1;
      cout << "Yes" << endl;
    } else if (S[i] == 'b' && b < B){
      b += 1;
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}