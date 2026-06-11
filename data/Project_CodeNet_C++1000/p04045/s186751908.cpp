#include <iostream>
using namespace std;
bool d[10] = {};

bool f(int n){
      while(n > 0){
            if(d[n % 10])return false;
            n /= 10;
      }
      return true;
}
int main(void){
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < k;i++){
          int c;
          cin >> c;
          d[c] = true;
    }
    
    while(!f(n)){
         n++; 
    }
    cout << n << endl;
    
    
}
