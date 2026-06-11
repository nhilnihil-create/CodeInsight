#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, ans = 0, x = 0; string S; cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'I') x++;
        else x--;
        ans = max(ans, x);
    }
    printf("%d\n", ans);
}
