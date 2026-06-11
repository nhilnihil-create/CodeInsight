#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std ;

typedef long long LL ;

const int N = 500010 ;

int n ;
LL f[N][4] ;


LL qr(){
    LL r = 0, f = 1 ;
    char c = getchar() ;
    while (!isdigit(c)){
        if (c == '-') f = -f ;
        c = getchar() ;
    }
    while (isdigit(c)){
        r = r * 10 + c - 48 ;
        c = getchar() ;
    }
    return r * f ;
}
int main(){
    cin >> n ; LL x ;
    f[0][1] = f[0][2] = -(1ll << 52) ;
    for (int i = 1 ; i <= n ; ++ i){
        x = qr() ;
        f[i][0] = x ;
        f[i][2] = x ;
        f[i][1] = -x ;
        f[i][2] += f[i - 1][2] ;
        f[i][1] += max(f[i - 1][1], f[i - 1][2]) ;
        f[i][0] += max(f[i - 1][0], max(f[i - 1][1], f[i - 1][2])) ;
        if (x < 0){
            f[i][2] = max(f[i][2], f[i][1]) ;
            f[i][1] = max(f[i][1], f[i][0]) ;
        }
    }
    cout << max(f[n][1], max(f[n][0], f[n][2])) << endl  ;
    return 0 ;
}

