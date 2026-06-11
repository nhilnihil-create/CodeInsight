#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int64_t X, T;
    cin >> X >> T;
    int64_t res = X - T;
    if (res > 0) {
        cout << res << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}