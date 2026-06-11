#include <bits/stdc++.h>
#include <tuple>
typedef long long int ll;
using namespace std;
int main() {
    int n, W;
    cin >> n >> W;
    ll w[n + 1];
    ll v[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    int num_of_w0 = 0; // w1 + 0
    int num_of_w1 = 0; // w1 + 1
    int num_of_w2 = 0;
    int num_of_w3 = 0;
    vector<ll> vecW0;
    vector<ll> vecW1;
    vector<ll> vecW2;
    vector<ll> vecW3;
    for (int i = 1; i <= n; i++) {
        if (w[i] == w[1]) {
            num_of_w0++;
            vecW0.push_back(v[i]);
        }
        else if (w[i] == w[1] + 1) {
            num_of_w1++;
            vecW1.push_back(v[i]);
        }
        else if (w[i] == w[1] + 2) {
            num_of_w2++;
            vecW2.push_back(v[i]);
        }
        else {
            num_of_w3++;
            vecW3.push_back(v[i]);
        }
    }
    sort(vecW0.begin(), vecW0.end(), greater<ll>());
    sort(vecW1.begin(), vecW1.end(), greater<ll>());
    sort(vecW2.begin(), vecW2.end(), greater<ll>());
    sort(vecW3.begin(), vecW3.end(), greater<ll>());
    //cout << vecW0[0] << endl;
    //cout << num_of_w0 << endl;
    ll dp[num_of_w0 + 2][num_of_w1 + 2][num_of_w2 + 2][num_of_w3 + 2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= num_of_w0; i++) {
        for (int j = 0; j <= num_of_w1; j++) {
            for (int k = 0; k <= num_of_w2; k++) {
                for (int l = 0; l <= num_of_w3; l++) {
                    if (i != num_of_w0) dp[i + 1][j][k][l] = dp[i][j][k][l] + vecW0[i];
                    if (j != num_of_w1) dp[i][j + 1][k][l] = dp[i][j][k][l] + vecW1[j];
                    if (k != num_of_w2) dp[i][j][k + 1][l] = dp[i][j][k][l] + vecW2[k];
                    if (l != num_of_w3) dp[i][j][k][l + 1] = dp[i][j][k][l] + vecW3[l];
                }
            }
        }
    }
    //cout << dp[1][0][0][0] << endl;
    ll max = 0;
    for (int i = 0; i <= num_of_w0; i++) {
        for (int j = 0; j <= num_of_w1; j++) {
            for (int k = 0; k <= num_of_w2; k++) {
                for (int l = 0; l <= num_of_w3; l++) {
                    if (W >= i * w[1] + j * (w[1] + 1) + k * (w[1] + 2) + l * (w[1] + 3)) {
                        if (max < dp[i][j][k][l]) {
                            max = dp[i][j][k][l];
                        }
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}