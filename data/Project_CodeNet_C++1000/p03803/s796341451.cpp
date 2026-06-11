#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A == 1)
        A = 14;
    if (B == 1)
        B = 14;
    if (A > B)
        cout << "Alice";
    if (A < B)
        cout << "Bob";
    if (A == B)
        cout << "Draw";
}