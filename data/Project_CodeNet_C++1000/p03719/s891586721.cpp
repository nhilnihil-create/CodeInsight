#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Anum, Bnum, Cnum;
    cin >> Anum >> Bnum >> Cnum;
    if (Anum <= Cnum && Bnum >= Cnum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}