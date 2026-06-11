#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int ans = 0;
    int now = 0;
    int N;
    string S;
    cin >> N >> S;

    for(int i = 0; i < N; i++) {
        if(S.at(i) == 'I') {
            now++;
        } else {
            now--;
        }
        ans = max(ans,now);
    }
    cout << ans << endl;

    return 0;
}