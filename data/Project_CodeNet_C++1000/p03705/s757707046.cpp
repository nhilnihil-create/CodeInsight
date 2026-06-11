#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
  // input
    long n,a,b;cin >> n >> a >> b;
    long ans;

  // compute
    //nは1を別処理
    if(n == 1){
        if(a == b){
            cout << 1 << endl;
            return 0;
        }else{
            cout << 0 << endl;
            return 0;            
        }
    }    

    ans = (n -2) * b - (n - 2) * a + 1;
    if(ans < 0){	
    	ans = 0;
    }

  // output  
    cout << ans << endl;

}