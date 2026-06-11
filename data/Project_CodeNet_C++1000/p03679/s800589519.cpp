#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i= (a); i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() { int X, A, B;
  cin >> X >> A >> B;
    if(A-B>=0){
      puts("delicious");
    }else if(A-B+X>=0){
      puts("safe");
    }else{
      puts("dangerous");
    }
  }
