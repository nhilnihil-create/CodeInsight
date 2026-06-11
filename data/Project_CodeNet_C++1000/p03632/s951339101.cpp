#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int main() {
int A,B,C,D;
cin >> A >> B >> C >> D;
if(min(B,D) - max(A,C) > 0) {
cout << min(B,D) - max(A,C) << endl;
} else cout << 0 << endl;


return 0;
}