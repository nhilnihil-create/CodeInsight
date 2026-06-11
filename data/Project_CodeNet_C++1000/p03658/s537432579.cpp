#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> l(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());

    int snake = 0;
    for (size_t i = 0; i < K; i++)
    {
        snake += l[i];
    }
    cout << snake << endl;
}
