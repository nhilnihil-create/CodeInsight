#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    /*
    O(K * N)解法
    「a以外の数字の組み合わせで作れる数字」を考えるため、両方向からdpテーブルを作る。
    */
    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    /*
    dp1[i][k]: i番目（0-indexed）以前の数字の和でkを作れるか否か
    dp2[j][k]: j番目（0-indexed）以降の数字の和でkを作れるか否か
    iについてのfor loopで
        dp[j][k] = dp1[j][k] (j < i)
                 = dp2[j][k] (j >= i)
    となるように更新していく
    */
    std::vector<std::vector<int>> dp(N, std::vector<int>(K));
    // 最初はdp2で初期化
    dp[N - 1][0] = 1;
    if (A[N - 1] < K) {
        dp[N - 1][A[N - 1]] = 1;
    }
    for (int j = N - 2; j >= 0; j--) {
        for (int k = 0; k < K; k++) {
            dp[j][k] = dp[j + 1][k];
            if (k >= A[j]) {
                dp[j][k] = std::max(dp[j][k], dp[j + 1][k - A[j]]);
            }
        }
    }
    // 「A[i] 以外の数字の組で K-A[i] ～ K-1 は作れない」ものの数を数える
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            bool is_unnessesary = std::all_of(
                dp[1].begin() + std::max(0, K - A[i]),
                dp[1].begin() + K,
                [](int a) {return a == 0;});
            if (is_unnessesary) cnt += 1;
            // dp1の反映
            for (int k = 0; k < K; k++) {
                dp[0][k] = 0;
            }
            dp[0][0] = 1;
            if (A[i] < K) dp[0][A[i]] = 1;
        } else if (i == N - 1) {
            bool is_unnessesary = std::all_of(
                dp[N - 2].begin() + std::max(0, K - A[i]),
                dp[N - 2].begin() + K,
                [](int a) {return a == 0;});
            if (is_unnessesary) cnt += 1;
        } else {
            // dp2の累積和
            for (int k = 1; k < K; k++) dp[i + 1][k] += dp[i + 1][k - 1];
            bool is_unnessesary = true;
            for (int x = 0; x < K; x++) {
                if (dp[i - 1][x] == 0) continue;
                // K - A[i] - x <= y <= K - 1 - x なるyの存在をチェック
                if (0 < K - A[i] - x) {
                    // dp[i + 1]はdp2の累積和になっていることに注意
                    if (dp[i + 1][K - 1 - x] - dp[i + 1][K - A[i] - x - 1] > 0) {
                        is_unnessesary = false;
                        break;
                    }
                } else if (K - A[i] - x <= 0 && 0 <= K - 1 - x) {
                    // dp[i + 1]はdp2の累積和になっていることに注意
                    if (dp[i + 1][K - 1 - x] > 0) {
                        is_unnessesary = false;
                        break;
                    }
                }
            }
            if (is_unnessesary) cnt += 1;
            // dp1の反映
            for (int k = 0; k < K; k++) {
                dp[i][k] = dp[i - 1][k];
                if (k >= A[i]) dp[i][k] = std::max(dp[i][k], dp[i - 1][k - A[i]]);
            }
        }
   }
   std::cout << cnt << std::endl;
   return 0;
}