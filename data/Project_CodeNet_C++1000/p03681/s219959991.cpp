#include <iostream>
using namespace std;

long long mod = 1e9+7;
long long fact(int n){
  if(n==0) return 1;
  return (n*fact(n-1))%mod;
}
int main(){
    long long n, m;
    cin >> n >> m;
    long long ans = fact(n)*fact(m)%mod;
    if(abs(n-m)>1){
        cout << 0 << endl;
    }else if(n==m){
        cout << (ans*2)%mod << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}