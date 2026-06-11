// Two Switches
#include <cmath>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int count = 0;
    if (min(B, D) > max(A, C)) count = min(B, D) - max(A, C);
    cout << count << endl;
}