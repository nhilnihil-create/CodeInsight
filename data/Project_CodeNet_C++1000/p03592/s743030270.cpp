#include <bits/stdc++.h>
using namespace std;
int main () {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i*j+(N-i)*(M-j) == K) {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
}