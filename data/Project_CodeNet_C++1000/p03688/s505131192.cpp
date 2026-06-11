#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10, INF = 1e9 + 10;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, a[MAXN];
main() {
    N = read();
    for(int i = 1; i <= N; i++) a[i] = read();
    sort(a + 1, a + N + 1);
    int mn = 0, mx = 0, num;
    a[0] = -1;
    for(int i = 1; i <= N; i++) 
        if(a[i] != a[i - 1]) {
            if(!mn) mn = a[i];
            else if(!mx) mx = a[i], num = i - 1;
            else {puts("No"); return 0;}
        }
    if(!mx) {
        if((mn == N - 1) || (mn * 2 <= N)) puts("Yes");
        else puts("No");
    } else {
        if((mx == mn + 1) && (2 * (mx - num) <= N - num) && (mx - num > 0)) puts("Yes");
        else puts("No");
    }
}