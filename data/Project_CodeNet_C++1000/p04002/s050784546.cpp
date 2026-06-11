#include<bits/stdc++.h>
using namespace std;

long long A[10];

int main() {
    int H, W, N, a, b;
    map<pair<int, int>, int> mp;
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (a+j > 0 && a+j < H-1 && b+k > 0 && b+k < W-1) {
                    mp[make_pair(a+j, b+k)]++;
                }
            }
        }
    }
    A[0] = (long long)(H-2) * (W-2);
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        A[itr->second]++;
        A[0]--;
    }
    for (int i = 0; i < 10; i++) {
        printf("%lld\n", A[i]);
    }
    return 0;
}