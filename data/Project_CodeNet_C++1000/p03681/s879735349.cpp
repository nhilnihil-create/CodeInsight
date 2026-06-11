#include<iostream>
using namespace std;

long long mod = 1000000007;

long long fac(long long x){
    if(x == 1) return 1;
    else return (fac(x - 1)*x)%mod;
}

int main(){
    long long n,m,ans = 0;
    cin >> n >> m;

    if(abs(n - m) > 1){
        ans = 0;
    }
    else{
        ans += fac(n);
        ans = (ans * fac(m))%mod;
        switch(abs(n - m)){
            case 1:
            break;
            case 0:
            ans = (ans*2)%mod;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}