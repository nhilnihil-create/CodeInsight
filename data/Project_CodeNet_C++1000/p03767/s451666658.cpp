#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(3 * N);
    for (int i = 0; i < 3 * N; i++)
    {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long int ans = 0;
    for (int i = 1; i < 2 * N; i += 2)
    {
        ans += v.at(i);
    }
    cout << ans;
}
