#include <bits/stdc++.h>
using namespace std;

const unsigned long long int maxv = pow(10,9) + 7;
int main(void){
  
    int N;
    cin >> N;
    unsigned long long int ans = 1;
    
    for(int i=1;i<=N;i++){
        ans *= i;
        if(ans > maxv) ans%= maxv;
    }
    
    cout << ans << endl;
}