#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Here your code !
    int n,t,m;
    cin >> n;
    
    (t = ceil((sqrt(1+8*n)-1) / 2));
    m = (t*(t+1))/2;
    
    for(int i = 1; i <= t; i++){
        if( n == m - i ){
        }
        else{
            cout << i << endl;
        }
    }
    
    
}
