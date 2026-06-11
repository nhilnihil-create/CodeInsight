#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int keta(long long b){
    int ans = 0;
    
    while (b > 0){
        b /= 10;
        ans++;
    }
    return ans;
}

int main(void){
   long long n;
   cin >> n;
   
   int ans = 16;
   
   for (long long i = 1; i * i <= n; i++){
       if (n % i != 0) continue;
       long long b = n / i;
       
       int temp1 = keta(i);
       int temp2 = keta(b);
       
       int temp3 = max(temp1,temp2);
       ans = min(ans,temp3);
   }
   cout << ans << endl;
}
