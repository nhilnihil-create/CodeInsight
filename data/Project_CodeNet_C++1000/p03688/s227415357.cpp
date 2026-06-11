#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }

    int a_s = a.at(0), a_l = a.at(0);
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        a_s = min(a_s, a.at(i));
        a_l = max(a_l, a.at(i));
        m[a.at(i)]++;
    }
    if (m.size() > 2 || a_l - a_s > 1)
    {
        cout << "No" << endl;
        return 0;
    }

    if (m.size() == 1)
    {
        int ai = a.at(0);
        if (ai == N - 1)
            cout << "Yes" << endl;
        else if (ai <= N / 2)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
    }

    int n_solo = m[a_s];
    int n_color = a_l;
    if (n_solo + 1 <= n_color && n_color <= n_solo + (N - n_solo) / 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
