#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<int> indices(N);
    bitset<300> omit;
    vector<int> counter(M);
    int ans = 1e9;
    for (int i = 0; i < M; i++) {
        fill(begin(counter), end(counter), 0);
        for (int j = 0; j < N; j++) {
            while (omit.test(A[j][indices[j]])) indices[j]++;
            counter[A[j][indices[j]]]++;
        }
        int sport = max_element(begin(counter), end(counter)) - begin(counter);
        ans = min(ans, counter[sport]);
        omit.set(sport);
    }
    cout << ans << endl;
    return 0;
}
