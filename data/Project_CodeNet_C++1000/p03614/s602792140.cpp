#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

extern inline char gc() {
    static char RR[23456], *S = RR + 23333, *T = RR + 23333;
    if(S == T) fread(RR, 1, 23333, stdin), S = RR;
    return *S ++;
}
inline int read() {
    int p = 0, w = 1; char c = gc();
    while(c > '9' || c < '0') { if(c == '-') w = -1; c = gc(); }
    while(c >= '0' && c <= '9') p = p * 10 + c - '0', c = gc();
    return p * w;
}

#define ri register int
#define sid 100050

int n, num;
int p[sid];

int main() {
    n = read();
    for(ri i = 1; i <= n; i ++) p[i] = read();
    for(ri i = 1; i <= n; i ++) {
        if(p[i] == i) {
            if(p[i + 1] != i) swap(p[i], p[i + 1]), num ++;
            else swap(p[i], p[i - 1]), num ++;
        }
    }
    printf("%d\n", num);
    return 0;
}