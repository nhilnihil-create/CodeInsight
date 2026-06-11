#include <bits/stdc++.h>
using namespace std;

int main()
{

    string A;
    cin >> A;
    int sz1 = A.size();

    string B;
    cin >> B;
    int sz2 = B.size();
    string C;
    cin >> C;


    if (A[sz1 -1] == B[0] && B[sz2-1] == C[0])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

