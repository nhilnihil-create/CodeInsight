#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        cin >> p.at(i);
    }

    vector<int> q(N);
    for (int i = 0; i < N; i++)
    {
        q.at(p.at(i) - 1) = i + 1;
    }

    vector<int> a(N), b(N);
    a.at(0) = 1;
    b.at(0) = q.at(0) - 1;
    for (int i = 1; i < N; i++)
    {
        a.at(i) = max(a.at(i - 1) + 1, q.at(i) - (b.at(i - 1) - 1));
        b.at(i) = q.at(i) - a.at(i);
    }
    int b_mn = b.at(N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << a.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << b.at(i) - b_mn + 1 << " ";
    }
    cout << endl;
    return 0;
}
