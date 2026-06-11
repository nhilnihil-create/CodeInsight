#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A,B;
    cin >> A >> B;

    if(24 <= A+B) cout << (A+B)-24;
    else cout << A+B;

    cout << endl;
    return 0;
}