#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

#define MAXN 100005

using namespace std;

template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
    if(c == '-') f = -1;
       c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 +c - '0';
        c = getchar();
    }
    res *= f;
}


int N,A,B;
char s[MAXN];
void Solve() {
    read(N);read(A);read(B);
    scanf("%s",s + 1);
    int r = 1,all = 0;
    for(int i = 1 ; i <= N ; ++i) {
        if(s[i] == 'a') {
            if(all < A + B) {puts("Yes");++all;}
            else puts("No");
        }
        else if(s[i] == 'b') {
            if(all < A + B && r <= B) {puts("Yes");++all;++r;}
            else puts("No");
        }
        else {
            puts("No");
        }
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
