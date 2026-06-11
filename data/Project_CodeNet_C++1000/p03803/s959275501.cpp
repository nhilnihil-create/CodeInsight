#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int A,B;
cin >> A >> B;
if (A == B) cout << "Draw" << endl;
else if (A == 1) cout << "Alice" << endl;
else if (B == 1 || B > A) cout << "Bob" << endl;
else if (A > B) cout << "Alice" << endl;

return 0;
}