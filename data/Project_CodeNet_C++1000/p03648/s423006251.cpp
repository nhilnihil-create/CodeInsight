#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define debug printf("%s %d\n", __FUNCTION__, __LINE__)
const int N = 50;

long long value[N + 1];
int main(int argc, char **argv) {
    long long k;
    cin >> k;
    long long w = k / N, t = k % N;
    w -= 1;
    if (k > N) {
        for (int i = 1; i <= N; i++) value[i] = w;
        for (int i = 1; i <= t; i++) value[i] += N + 2 - i;
        for (int i = t + 1; i <= N; i++) value[i] += N + 1 - i;
    }
    else if (k <= N) {
        for (int i = 1; i <= k; i++) value[i] = N - i + 1;
        for (int i = k + 1; i <= N; i++) value[i] = 0;
    }

    cout << N << endl;
    for (int i = 1; i <= N; i++) 
        cout << value[i] << ' ';
    cout << endl;
    return 0;
}