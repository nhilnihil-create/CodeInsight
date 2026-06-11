#include <iostream>
#include <algorithm>
using namespace std;
int main(void){

    int A,B,C;
    cin >> A >> B >> C;
    
    long long S = A;
    
    bool can = false;
    for(int i=0;i<B;i++){
        S = S * (i+1) ;
        if(S<i)break;
        int origin = i*B+C;
        if(origin%A==0){
            can = true;
            break;            
        }
    }
    
    if(can) cout << "YES";
    else cout << "NO";
    
}