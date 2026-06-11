#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long C, K;
    cin >> C >> K;

    vector<long> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }
    sort(T.begin(), T.end());

    int result = 0;
    for (int i = 0; i < N;)
    {
        result++;
        int t = i;
        while (i - t + 1  <= C && T[i] - T[t] <= K && i < N)
            i++;
    }
    cout << result << endl;
}
