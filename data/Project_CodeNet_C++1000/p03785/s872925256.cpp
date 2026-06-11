#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T;
    T.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    sort(T.begin(), T.end());
    int lim = T[0] + K;
    int p = 0;
    int ans = 1;
    for (int n : T)
    {
        if (n > lim || p == C)
        {
            ans++;
            p = 1;
            lim = n + K;
            continue;
        }else
        {
            p++;
        }

    }

    cout << ans << endl;

    return 0;
}