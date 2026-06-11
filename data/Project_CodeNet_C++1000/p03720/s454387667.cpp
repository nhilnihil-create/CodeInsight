#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, x, y;
    cin >> N >> M;
    vector<int> vec(N, 0);
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y;
        ++vec.at(x - 1);
        ++vec.at(y - 1);
    }
    for (int i = 0; i < N; ++i)
    {
        cout << vec.at(i) << endl;
    }
}