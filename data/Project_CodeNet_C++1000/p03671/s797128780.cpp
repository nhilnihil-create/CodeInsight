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
int a,b,c;
cin >> a >> b >> c;
int ans = a+b+c;
if(a<=b&&c<=b) {
  cout << ans-b << endl;
} else if(a<=c&&b<=c) {
  cout << ans-c << endl;
} else {
  cout << ans-a << endl;
}
return 0;
}
