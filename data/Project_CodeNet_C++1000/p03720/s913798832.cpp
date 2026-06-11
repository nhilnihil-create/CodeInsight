#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int x;
    vector<int> v(N + 1);
    for (int i = 0; i < 2 * M; i++)
    {
        cin >> x;
        v.at(x) += 1;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << v.at(i) << endl;
    }
}
