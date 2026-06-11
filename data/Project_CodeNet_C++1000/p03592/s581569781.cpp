#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n , m , k ;
    bool f = false;
    
    cin >> n >> m >> k;
    
    for(int i=0 ;i<=n ;i++ ){
        for(int j=0 ;j<=m ;j++ ){
            if( i*m + j*n - 2 *(i*j) == k){
                f = true;
            }
        }
    }
    
    if(f){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return(0);
}