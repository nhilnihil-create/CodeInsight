#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1000000000;

int main() {
    int N;
    int ans = 0;
    cin >> N;
    vector<pair<int, int>> A_B(N);

    for (int i = 0; i < N; i++) {
        cin >> A_B[i].first >> A_B[i].second;
    }
    sort(A_B.begin(), A_B.end());
    
    ans += A_B[0].first;
    for (int i = 1; i < N; i++) {
        ans += min((A_B[i].first-A_B[i-1].first), (A_B[i-1].second-A_B[i].second));
    }
    ans += A_B[N-1].second;

    cout << ans << endl;
}
