#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define ri register int
#define sid 200050

char s[sid];
int nxt[sid][26], f[sid];

int main() {

    scanf("%s", s + 1);
    int n = strlen(s + 1);

    for(ri i = 0; i < 26; i ++) nxt[n][i] = n + 1;
    for(ri i = n - 1; i >= 0; i --) {
        for(ri j = 0; j < 26; j ++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }

    for(ri i = n; i >= 0; i --) {
        f[i] = 1e9;
        for(ri j = 0; j < 26; j ++)
        f[i] = min(f[i], 1 + f[nxt[i][j]]);
    }

    int o = 0;
    while(o != n + 1) {
        for(ri j = 0; j < 26; j ++)
        if(f[o] == f[nxt[o][j]] + 1) {
            o = nxt[o][j]; 
            printf("%c", j + 'a'); break;
        }
    } 
    return 0;
}