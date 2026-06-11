#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main() {
  char a,b;
  cin >> a >>b;
  if(a=='H' && b=='H'){cout << 'H' << endl;}else
  if(a=='H' && b=='D'){cout << 'D' << endl;}else  
  if(a=='D' && b=='H'){cout << 'D' << endl;}else
  if(a=='D' && b=='D'){cout << 'H' << endl;}
}