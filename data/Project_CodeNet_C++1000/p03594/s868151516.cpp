// ※※※ 解答不能 ※※※
// LHiC氏.
// https://atcoder.jp/contests/code-festival-2017-quala/submissions/1617008
#include <bits/stdc++.h>
using namespace std;
int h, w, d;
int c[1200];
char s[1200][1200];

int main(){
    scanf("%d %d %d", &h, &w, &d);
    for(int i = 0; i < h + w - 1; ++i){
        if(i >= d) c[i] = c[i - d] ^ 1;
        else       c[i] = 0;
    }
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int a = c[i + j] * 2 + c[i + (w - 1 - j)];
            if(a == 0)       s[i][j] = 'R';
            else if (a == 1) s[i][j] = 'G';
            else if (a == 2) s[i][j] = 'B';
            else             s[i][j] = 'Y';
        }
    }
    for(int i = 0; i < h; ++i) printf("%s\n", s[i]);
    return 0;
}