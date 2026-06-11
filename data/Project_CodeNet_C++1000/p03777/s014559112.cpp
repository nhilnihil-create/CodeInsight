#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;



int main(){
  char a, b;
  cin >> a >> b;
  if (a == 'H'){
    if (b == 'H') cout << "H\n";
    else cout << "D\n";
  } else {
    if (b == 'D') cout << "H\n";
    else cout << "D\n";
  }
}