#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    cout << (A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0] ? "YES" : "NO") << endl;
}