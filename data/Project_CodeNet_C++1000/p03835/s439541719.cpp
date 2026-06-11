#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int K, S, cnt = 0;
    scanf("%d %d", &K, &S);
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            if (S - (i + j) >= 0 && S - (i + j) <= K) cnt++;
        }
    }
    printf("%d\n", cnt);
}