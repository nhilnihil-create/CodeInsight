#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    int x = max(A,C);
    int y = min(B,D);

    cout << max(0,y-x);
}