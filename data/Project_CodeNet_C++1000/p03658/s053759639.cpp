#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K, l, a;
    vector<int> v;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> l;
        v.push_back(l);
    }

    sort(v.begin(), v.end(),greater<>());

    for (int i = 0; i < K; i++)
    {
        a = v[i] + a;
    }
    cout << a;
}