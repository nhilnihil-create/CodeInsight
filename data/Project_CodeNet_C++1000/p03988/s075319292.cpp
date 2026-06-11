#include <bits/stdc++.h>
using namespace std;
using Int = long long;
bool solve(vector<int> A)
{
    int counter[100] = {};
    for (auto a : A) counter[a]++;
    bool first = true;
    int max = 1e9;
    for (int i = 0; i < 100; i++) {
        if (first && counter[i]) {
            if (counter[i] == 1) max = i * 2;
            else if (counter[i] == 2) max = i * 2 - 1;
            else return false;
            first = false;
        } else if (!first && i <= max) {
            if (counter[i] < 2) return false;
        } else if (!first) {
            if (counter[i] != 0) return false;
        }
    }
    return true;
}
int main() 
{
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    cout << (solve(A) ? "Possible" : "Impossible") << endl;
    return 0;
}