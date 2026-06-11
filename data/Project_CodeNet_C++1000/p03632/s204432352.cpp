#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int sec = 0;
    if (C <= B && A <= D)
    {
        //if (A == C && B == D)
        //    sec = B - A; // or D - C
        if (A <= C && D <= B)
            sec = D - C;
        else if (A <= C && B <= D)
            sec = B - C;
        else if (C <= A && B <= D)
            sec = B - A;
        else 
            sec = D - A;
    }
    cout << sec << endl;
    return 0;
}