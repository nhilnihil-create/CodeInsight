#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main()
{
    int64_t N, M;
    cin >> N >> M;
    int64_t total, camari;
    camari = M - N * 2;
    if (camari <= 0)
    {
        total = M / 2;
        cout << total << endl;
    }
    else
    {
        int64_t camari4 = camari / 4;
        total = N + camari4;
        cout << total << endl;
    }
}