#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int A,B,C,D;
cin >> A >> B >> C >> D;
if (A*B >= C*D) cout << A*B << endl;
else cout << C*D << endl;

return 0;
}