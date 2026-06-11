#include <bits/stdc++.h>

using namespace std;

int freq[(int)1e5 + 5];

int main()
{
    cin.tie(0);
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int v; cin >> v; v++;
        freq[v]++;
        freq[v - 1]++;
        freq[v + 1]++;
    }
    int best = 0;
    for (int i = 0; i < (int)1e5 + 5; i++) best = max(best, freq[i]);
    cout << best << "\n";
}