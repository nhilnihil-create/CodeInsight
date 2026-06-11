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
int A,B,C;
cin >> A >> B >> C;
string ans = "No";
if(A<=C&&C<=B) ans = "Yes";
cout << ans << endl;
return 0;
}
