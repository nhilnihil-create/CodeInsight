#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
int x,t;
cin >> x >> t;
if(t<=x) {
  cout << x-t << endl;
} else {
  cout <<"0" <<endl;
}
return 0;
}
