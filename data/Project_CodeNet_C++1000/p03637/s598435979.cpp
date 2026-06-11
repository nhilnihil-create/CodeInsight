#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int N;
    cin >> N;
    int fac2 = 0, fac4 = 0, fr = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp % 4 == 0)
            fac4++;
        else if (tmp % 2 == 0)
            fac2++;
        else
            fr++;
    }
    int mfac4 = N - fac4 * 2;
    if (fac2 == 0)
    {
        if (fac4 >= (fr - 1))
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        if (fac4 >= fr)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
    }
}