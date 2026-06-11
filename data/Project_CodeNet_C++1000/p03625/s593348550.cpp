#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;
    map<int64_t, int> stick;
    rep(i, N)
    {
        int64_t A;
        cin >> A;
        stick[A]++;
    }
    int64_t tate = 0, yoko = 0;
    for (auto x : stick)
    {
        if (x.second >= 4)
        {
            tate = x.first;
            yoko = x.first;
        }
        else if (x.second >= 2)
        {
            tate = yoko;
            yoko = x.first;
        }
    }
    cout << tate * yoko << endl;
}