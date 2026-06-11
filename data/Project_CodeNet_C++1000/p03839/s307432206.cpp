#include <stdio.h>
 
int main(void) {
    int N, M;

    /**** 入力 ****/
    scanf("%d %d", &N, &M);
 
    int ai[N+1];
    for (int i=1; i<=N; i++) {
        scanf("%d", &ai[i]);
    }

    /**** 事前準備（累積和） ****/
    // 10^9 * 10^5が32bitを超えるので64bit確保
    long long sum[N+1];     // 全データの累積和
    long long plusSum[N+1]; // 正の数だけの累積和
    sum[0] = 0;
    plusSum[0] = 0;
    for (int i=1; i<=N; i++) {
        sum[i] = sum[i-1] + ai[i];
        if (ai[i] > 0) {
            plusSum[i] = plusSum[i-1] + ai[i];
        } else {
            plusSum[i] = plusSum[i-1];
        }
    }

    /**** 計算 ****/
    long long max = 0;
    for (int i=0; i<N-M+1; i++) {
        // 最後に塗るMマスがi番目のマスから始まる場合のスコアを計算
        int left = i;           // Mマスの左端
        int right = i + M - 1;  // Mマスの右端

        long long total = 0;        
        total += sum[right+1] - sum[left];   // 最後に黒く塗った領域のスコア
        if (total < 0) {
            total = 0;  // 黒く塗って負数になる場合は白く塗って0にする
        }
        total += plusSum[left];   // 左側の正の数の総和
        total += plusSum[N] - plusSum[right+1];  // 右側の正の数の総和

        if (max < total) {
            max = total;    // 過去最高なら保持
        }
    }

    /**** 出力 ****/
    printf("%lld\n", max);
  
	return 0;
}
