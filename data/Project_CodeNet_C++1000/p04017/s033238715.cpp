#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e5 + 7 ; 

int n;
int a[N] , b[N] ,c [N]; 
int L , m ; 
int nei[N] ; 

int fat[N][28] ; 

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    //freopen("in.in" , "r" , stdin) ;
    cin>>n ; 
    int l = 0  , l1 = 0 ; 
    for(int i = 1 ;i <= n;i++){
        cin>>a[i] ;
        l = a[i] ; 
        a[i]-= l1  ; 
        l1 = l ; 
    }  
    cin>>L ; 
    int mx = 1 ;
    int sum = 0 ;  
    int j = 1 ; 
    a[1] = 0 ; 
    for(int i = 1 ;i <= n ;i++){
        if( i > 1)
            sum-=a[i] ;
        while( j + 1 <= n && sum + a[j+1] <= L ){
            sum+=a[j+1] ; 
            j++ ;
        }
        nei[i] = j ; 
        fat[i][0] = j ; 
    }
    for(int i = 1 ; i < 26 ; i++){
        for(int j = 1 ; j <= n ;j++){
            fat[j][i] = fat[ fat[j][i-1] ][i-1] ; 
        }
    }
    cin>>m ;
    while(m--){
        int l , r; 
        cin>>l >>r ; 
        if(l > r) swap(l , r) ;
        int ans = 0  ;
        for(int i = 25 ; i >=0 ; i-- ){
            if(fat[l][i] < r)
            {
                l = fat[l][i] ; 
                ans+=(1<<i) ; 
            }
        }
        cout<< ans+1<<"\n" ; 
    }
    return 0 ;
}