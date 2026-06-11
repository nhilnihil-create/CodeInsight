#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    int sum = accumulate(A.begin(),A.end(), 0);
    int ans = sum*(sum%10 != 0);
    for(int i = 0; i < N; i++) {
        if((sum - A.at(i))%10) {
            ans = max(ans, sum - A.at(i));
        }
    }
    cout << ans << endl;

    return 0;
}