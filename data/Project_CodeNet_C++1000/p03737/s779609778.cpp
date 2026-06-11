#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    string A, B, C, ans = "";
    cin >> A >> B >> C;

    ans += A[0] - 0x20;
    ans += B[0] - 0x20;
    ans += C[0] - 0x20;
    cout << ans << endl;

    return 0;
}
