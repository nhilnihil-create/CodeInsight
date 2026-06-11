#include <bits/stdc++.h>
using namespace std;

int main() {

    int A ,B ,C,D;
    cin >> A >> B >> C >> D;

    int start = max(A, C);
    int end = min(B, D);
    cout << max(end - start, 0) << endl;

    return 0;
}