#include <bits/stdc++.h>
using namespace std;

int main(void){
   
    int W,a,b;
    cin >> W >> a >> b;
   
    if(a > b){
       swap(a,b);
    }
    
    if(a + W < b){
        cout << b - (a + W) << endl;
    }
    else{
        cout << 0 << endl;
    }
}