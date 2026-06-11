#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int A, B, C, D;
    int AB, CD;
    cin >> A >> B >> C >> D;
    AB = A * B;
    CD = C * D;
    if (AB > CD)
    {
        cout << AB << endl;
    }
    else
    {
        cout << CD << endl;
    }
}