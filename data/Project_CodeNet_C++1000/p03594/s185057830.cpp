#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <cmath> 
#include <algorithm>
using namespace std; 

const char s[] = "RGBY";
int N, M, D;

int main() { 
    cin >> N >> M >> D; 
    for (int i = 0; i < N; i++, putchar('\n'))
        for (int j = 0, x, y; j < M; j++)
            x = (M + i + j) / D % 2,
            y = (M + i - j) / D % 2,
            putchar(s[2 * x + y]);
    return 0;
}