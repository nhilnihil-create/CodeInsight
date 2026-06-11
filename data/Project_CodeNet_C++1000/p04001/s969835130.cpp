#include <bits/stdc++.h>
using namespace std;

using ll = long long ;

int main() {
    string S ;
    cin >> S ;
    
    ll N = S.size() ;
    ll ans = 0 ;
    
    for( int tmp=0 ; tmp < ( 1 << (N-1) ) ; tmp++ ){
        
        bitset<10> p( tmp ) ;
        
        string K = S ;
        ll k = K.size() ;
        
        for( int i = 0 ; i<10 ; i++ ){
            
            if( p.test(i) ){
                
                K = K.insert( ( N - (i+1) ) , " " ) ;
        
            }
        }
        k = K.size() ;
        
        vector<char> A(k) ;
        ll a = A.size() ;
        
        for( int i=0 ; i<k ; i++){
            
            A.at(i) = K.at(i) ;
              
        }
        
        ll ans1 = 0 ;
        ll ans2 = 0 ;
        
        for( int i=0 ; i<a ; i++ ){
            
            if( A.at(i) == ' ' ){
                ans2 += ans1 ;
                ans1 = 0 ;
            }
            else{
                ll an = A.at(i) - '0' ;
        
                ans1 = ans1*10 + an ;
        
            }
        }
        ans2 += ans1 ;
        ans += ans2 ;
        
    }
    cout << ans << endl;
}

