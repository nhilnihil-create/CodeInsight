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

    vector<bool> b(N);
    b.at(0) = true;

    int ans = 0;
    int next_light = a.at(0) - 1;
    while (true)
    {
        ans++;
        if (next_light == 1)
        {
            break;
        }
        next_light = a.at(next_light) - 1;
        if (b.at(next_light))
        {
            ans = -1;
            break;
        }
        b.at(next_light) = true;
    }

    cout << ans << endl;
    return 0;
}