#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, c, c7 = 0, c5 = 0;
    cin >> a >> b >>c;
    
    if(a == 5){
        c5++;
    } else if(a == 7){
        c7++;
    }
    
    if(b == 5){
        c5++;
    } else if(b == 7){
        c7++;
    }
    
    if(c == 5){
        c5++;
    } else if(c == 7){
        c7++;
    }
    
    
    if(c7 == 1 && c5 == 2 ){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    
    //cout << a.at(b - 1) << endl;

    return 0; 
}
