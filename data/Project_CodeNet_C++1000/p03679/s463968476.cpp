#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long mod=1e9+7;

int main() {
  int A, B, X;
  cin >> X >> A >> B;
  if(B-A <= 0){
    cout << "delicious" << endl;
  }else if(B-A <= X){
    cout << "safe" << endl;
  }else{
    cout << "dangerous" << endl;
  }
}