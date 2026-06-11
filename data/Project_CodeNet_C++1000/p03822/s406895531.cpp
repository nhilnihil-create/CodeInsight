#include <bits/stdc++.h>
using namespace std;
vector<int> A[100000];

int solve(int i) {
    int res = 0;
    vector<int> V;
    for(int v : A[i]) V.push_back(solve(v));
    sort(V.begin(), V.end());
    for(int i=0; i<V.size(); ++i) res = max(res + 1, V[i]);
    return res + 1;
}

int main() {
    int N;
    cin >> N;
    for(int i=1; i<N; ++i) {
        int a;
        cin >> a;
        A[a-1].push_back(i);
    }

    cout << solve(0) - 1 << endl;
}