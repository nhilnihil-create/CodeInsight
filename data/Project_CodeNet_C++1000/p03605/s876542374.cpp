#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    int d10 = N / 10;
    int d1 = N - d10 * 10;
    if (d10 == 9 || d1 == 9)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}