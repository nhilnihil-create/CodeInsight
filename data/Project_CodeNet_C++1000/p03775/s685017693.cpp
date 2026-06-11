#include <iostream>
#include <algorithm>

using namespace std;

long long keta(long long n){
    long long cnt = 0;
    
    while (n > 0){
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main(void){
   long long n;
   cin >> n;
   
   long long ans = 100;
   
   for (long long i = 1; i * i <= n; i++){
       if (n % i != 0) continue;
       
       long long temp = n / i;
       
       long long a = keta(i);
       long long b = keta(temp);
       
       ans = min(ans, max(a,b));
   }
    
    cout <<  ans << endl;;
}
