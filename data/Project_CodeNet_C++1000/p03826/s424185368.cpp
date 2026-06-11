#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (((a) < (b)) ? (b) : (a))
int main(void) {
    int64_t A,B,C,D;

    cin >> A >> B >> C >> D;
    cout << max(A*B,C*D) << "\n";

    return 0;
}
