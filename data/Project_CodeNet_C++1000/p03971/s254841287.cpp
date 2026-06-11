#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N, A, B, X, t = 0, tb = 0;
  string S;
  
  cin >> N >> A >> B;
  cin >> S;
  X = A + B;
  
  for(int i = 0; i < N; i++){
    if(S.at(i) == 'c'){
      cout << "No" << endl;
    }
    else if(S.at(i) == 'a' && X > t){
      cout << "Yes" << endl;
      t += 1;
    }
    else if(S.at(i) == 'b' && X > t && B > tb){
      cout << "Yes" << endl;
      t += 1;
      tb += 1;
    }
    else{
      cout << "No" << endl;
    }
  }
}
