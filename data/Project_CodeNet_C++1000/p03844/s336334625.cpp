#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, x;
    char op;
    cin >> A >> op >> B;
    x = op == '+'? A + B:A - B;
    cout << x << endl;
}