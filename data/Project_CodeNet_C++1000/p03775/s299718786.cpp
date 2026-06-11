#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    int ans = 10;
    
    for(int i = 1; i <= sqrt(n); i++) {
     if(n % i == 0) {
      int keta = 0;
      long long syou = n / i;
         while(syou > 0) {
             syou /= 10;
          keta++;
         }
         ans = min(ans, keta);
     }
    }
    cout << ans;
}