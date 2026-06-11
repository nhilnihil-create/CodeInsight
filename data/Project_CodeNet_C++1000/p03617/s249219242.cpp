#include <bits/stdc++.h>
using namespace std;


int main(void){
    
    long long Q,H,S,D;
    long long N;
    
    cin >> Q >> H >> S >> D;
    cin >> N;
    
    S = min (S, H * 2 );
    S = min (S, Q * 4 );
    
    if(N%2 == 0){
        
        cout << min(N*S,(N/2)*D);
        
        
    }else{
        
        cout << min(N*S,(N/2)*D+S);
        
        
    }
    
}
