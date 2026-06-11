#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std ;

const int P = 1000000007 ;

int n ;
int yes[600000] ;
int base[600000] ;

int expow(int a, int b){
    int res = 1 ;
    while (b){
        if (b & 1)
            res = 1ll * a * res % P ;
        a = 1ll * a * a % P ; b >>= 1 ;
    }
    return res ;
}
int main(){
    cin >> n ;
    for (int i = 1 ; i <= n ; ++ i) scanf("%d", &base[i]) ;
    sort(base + 1, base + n + 1) ;
    if (n & 1){
        yes[1] = 0 ; int cnt = 0 ;
        for (int i = 2 ; i <= n ; i += 2)
            yes[i] = yes[i + 1] = 2 * (++ cnt) ;
        for (int i = 1 ; i <= n ; ++ i)
            if (base[i] != yes[i]) return printf("0\n"), 0 ;
    }
    else{
        int cnt = 0 ;
        yes[1] = yes[2] = ++ cnt ;
        for (int i = 3 ; i <= n ; i += 2)
            yes[i] = yes[i + 1] = (cnt += 2) ;
        for (int i = 1 ; i <= n ; ++ i)
            if (base[i] != yes[i]) return printf("0\n"), 0 ;
    }
    return printf("%d\n", expow(2, n / 2)), 0 ;
}
