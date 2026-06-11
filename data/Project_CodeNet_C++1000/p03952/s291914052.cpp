#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, x;
    cin >> N >> x;
    M = 2 * N - 1;
    if(2 <= x && x <= M - 1) { // exists
        vector<int> ans(M);
        set<int> numbers;
        ans[N - 1] = x;
        int sgn = 2 < x ? -1 : 1;
        numbers.insert({x - 1, x, x + 1, x + sgn * 2});
        ans[N] = x + sgn * 1;
        if(N > 2) ans[N + 1] = x + sgn * 2;
        ans[N - 2] = x - sgn * 1;
        for(int i = 0, j = 1; i < M; i++) {
            if(N - 2 <= i && i <= N + 1) continue;
            while(numbers.count(j)) j++;
            ans[i] = j;
            numbers.insert(j++);
        }
        cout << "Yes" << endl;
        for(int i = 0; i < M; i++) {
            cout << ans[i] << endl;
        }
    } else {
        cout << "No" << endl;
    }
    return 0;
}