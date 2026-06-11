#include<bits/stdc++.h>

using namespace std ;

#define N 200007

int tot , n ;
int nex[2*N] , fire[N] , to[2*N] , sg[N] ;

void add(int u , int v){
    nex[++tot] = fire[u] ;
    fire[u] = tot ;
    to[tot] = v ;
    return ;
}

void dfs(int x , int fr){
    for(int i = fire[x] ; i ; i = nex[i] ){
        int v = to[i] ;
        if( v == fr ) continue ;
        dfs( v , x ) ;
        sg[x] ^= ( sg[v] + 1 ) ;
    }
    return ;
}

int main()
{
    scanf("%d" , &n ) ;
    for(int i = 1 ; i <= n - 1 ; i++ ){
        int u , v ;
        scanf("%d%d" , &u , &v ) ;
        add( u , v ) ; add( v , u ) ;
    }
    dfs( 1 , 0 ) ;
    if( sg[1] ) printf("Alice\n") ;
    else printf("Bob\n") ;
    return 0 ;
}