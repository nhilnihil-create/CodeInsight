#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t A, B;
    char op;
    cin >> A >> op >> B;
    if (op == '+') {
        cout << A + B << endl;
    } else {
        cout << A - B << endl;
    }
    return 0;
}