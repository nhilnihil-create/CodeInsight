#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int a, b;
  cin >> a >> b;
  if (a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
} 