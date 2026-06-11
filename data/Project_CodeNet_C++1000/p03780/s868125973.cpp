#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int MAX_N = 5005;
const ll MAX_K = 5005;
const ll INF = 1LL << 40;

bool dp[MAX_N][MAX_K];

int main() {
    int N;
    ll K, A;
    cin >> N >> K;
    vector<ll> a;
    for (int i = 0; i < N; i++) {
        cin >> A;
        a.push_back(A);
    }
    a.push_back(-1);
    a.push_back(INF);
    sort(a.begin(), a.end()); // 0とN+1番目は0とINFが入っている
    int left = 0, right = a.size() - 1; // left:必ず不要, right:必ず必要
    while (right - left > 1) {
        int mid = (right + left) / 2;
        // i番目のカードが不要かどうかを確かめる
        vector<ll> other_a;
        for (int j = 1; j <= N; j++) {
            if (mid == j) continue;
            other_a.push_back(a[j]);
        }
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < K; k++) dp[j][k] = false;
        }
        for (int j = 0; j < N; j++) dp[j][0] = true;
        for (int j = 1; j <= other_a.size(); j++) {
            for (ll k = 0; k < K; k++) {
                dp[j][k] = dp[j - 1][k];
                if (k - other_a[j - 1] >= 0) dp[j][k] |= dp[j - 1][k - other_a[j - 1]];
            }
        }
        bool is_needed = false;
        for (ll j = 0; j < K; j++) {
            if (dp[N - 1][j] && j + a[mid] >= K) {
                is_needed = true;
                break;
            }
        }
        if (!is_needed) left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}