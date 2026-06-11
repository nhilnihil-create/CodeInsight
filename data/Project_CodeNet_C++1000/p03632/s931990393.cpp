#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define repr(i,n) for(int i=0, i##_len=(n); i<i##_len; --i)
#define REP(i,m,n) for(int i=int(m), i##_len=(n); i<i##_len; ++i)
#define VV(T) vector<vector<T>>
#define co(P) cout << P << endl
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;;
typedef long long ll;
typedef double D;

int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D;
  if(A>=C) E = A;
  else E = C;
  if(B>=D) F = D;
  else F = B;
  if(F-E>=0)co(F-E);
  else co(0);
}