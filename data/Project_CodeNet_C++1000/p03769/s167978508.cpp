#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N; cin >> N;
    N++;

    auto prefix = vector<int>(), suffix = vector<int>();
    for (auto i = 1; N > 1; i++)
    {
        if (N % 2 == 0)
        {
            prefix.push_back(i);
            N /= 2;
        }
        else
        {
            suffix.push_back(i);
            N--;
        }
    }
    reverse(begin(suffix), end(suffix));

    const auto K = int(prefix.size() + suffix.size());
    cout << 2*K << endl;

    for (const auto x : prefix) cout << x << " ";
    for (const auto x : suffix) cout << x << " ";

    for (auto i = 1; i <= K; i++)
        cout << i << " ";
    cout << endl;
}
