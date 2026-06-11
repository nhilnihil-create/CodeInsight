#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
typedef long long LL;

LL n, p[100];


int main( int argc , char * argv[] ){
//	freopen( "input.txt" , "r" , stdin );
//	freopen( "output.txt" , "w" , stdout );
    int i, L, l, r, m; p[0] = 1;
    char c;
	for(i = 1; i <= 12; ++i){
        p[i] = p[i - 1] * 10;
	}
	printf("? %lld\n", p[12]);
	fflush(stdout);
    scanf(" %c", &c);
    if(c == 'Y'){
        for(i = 1; i <= 12; ++i){
            printf("? %lld\n", p[i] - 1);
            fflush(stdout);
            scanf(" %c", &c);
            if(c == 'Y') break;
        }
        printf("! %lld\n", p[i - 1]);
    }
    else{
        for(i = 1; i <= 12; ++i){
            printf("? %lld\n", p[i]);
            fflush(stdout);
            scanf(" %c", &c);
            if(c == 'N') break;
        }
        L = i;
        for(i = 1; i < L; ++i){
            n *= 10;
            for(l = 0, r = 9; l < r;){
                m = (l + r + 1) >> 1;
                printf("? %lld\n", n + m);
                fflush(stdout);
                scanf(" %c", &c);
                if(c == 'Y') l = m;
                else r = m - 1;
            }
            n += l;
        }
        n *= 10;
        for(i = L == 1 ? 1 : 0; i <= 9; ++i){
            printf("? %lld\n", (n + i) * 10 + 9);
            fflush(stdout);
            scanf(" %c", &c);
            if(c == 'Y') break;
        }
        n += i;
        printf("! %lld\n", n);
	}
	return 0;
}
