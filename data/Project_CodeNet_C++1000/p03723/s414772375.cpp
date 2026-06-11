#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;


int main()
{

  int A, B, C;
  cin >> A >> B >> C;
  int a = A, b = B, c = C;
 
  int cost = 0;
 
  while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    int latte = a / 2;
    int malta = b / 2;
    int beet = c / 2;
    a = malta + beet;
    b = latte + beet;
    c = latte + malta;
 
    ++cost;
    if(A == a && b == B && c == C) {
      cout << -1 << endl;
      return (0);
    }
  }
 
  cout << cost << endl;
}
