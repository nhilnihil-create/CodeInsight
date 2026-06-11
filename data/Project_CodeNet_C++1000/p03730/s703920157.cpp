#include <bits/stdc++.h>
using namespace std;

int main()
{

    int A, B, C;
    cin >> A >> B >> C;

    int target = A;

    bool ans = false;

    while (target % B != 0)
    {
        if (target % B == C)
        {
            ans = true;
            break;
        }
        target += A;
    }

    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}