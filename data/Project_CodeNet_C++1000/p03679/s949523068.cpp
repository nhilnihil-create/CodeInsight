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
int x,a,b;
cin >> x >> a >> b;
if(a>=b) {
  cout << "delicious" <<endl;
} else if(a<b&&b<=a+x) {
  cout << "safe" << endl;
} else {
  cout << "dangerous" << endl;
}
return 0;
}
