#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int ai[N+1];
    for (int i=1; i<=N; i++) {
        scanf("%d", &ai[i]);
    }

    long long bestScores[N+1];
    long long blackScores[N+1];
    // white scores is always 0.
    bestScores[0] = 0;
    blackScores[0] = 0;
    for (int i=1; i<=N; i++) {
        if (ai[i] > 0) {
            bestScores[i] = bestScores[i-1] + ai[i];
        } else {
            bestScores[i] = bestScores[i-1];
        }
        blackScores[i] = blackScores[i-1] + ai[i];
    }

    long long maxBlackDiff = -100000000000001L;
    long long maxWhiteDiff = -100000000000001L;
    for (int i=1; i<=N-K+1; i++) {
        long long best = bestScores[i+K-1] - bestScores[i-1];
        long long black = blackScores[i+K-1] - blackScores[i-1];
        long long white = 0;

        long long blackDiff = black - best;
        long long whiteDiff = white - best;
        if (blackDiff > maxBlackDiff) {
            maxBlackDiff = blackDiff;
        }
        if (whiteDiff > maxWhiteDiff) {
            maxWhiteDiff = whiteDiff;
        }
    }
    
    long long result = 0;
    if (maxBlackDiff > maxWhiteDiff) {
        result = bestScores[N] + maxBlackDiff;
    } else {
        result = bestScores[N] + maxWhiteDiff;
    }

    printf("%lld\n", result);
  
	return 0;
}
