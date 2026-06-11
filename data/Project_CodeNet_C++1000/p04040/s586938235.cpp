#include <iostream>
using namespace std;
const long long MOD = 1e9+7;
long long modinv(long long a,long long MOD){
    long long k = MOD-2;
    long long p = 1;
    while(k>0){
        if(k%2==1) p*=a;
        k/=2;
        a*=a;
        a%=MOD;
        p%=MOD;
    }
    return p;
}
int main(){
    long long h,w,a,b;
    cin >> h >> w >> a >> b;
    long long fac[2*max(h,w)+1];
    fac[0]=1;
    for(int i = 0;i<2*max(h,w);i++){
        fac[i+1]=fac[i]*(i+1);
        fac[i+1]%=MOD;
    }
    long long ans = 0;
    long long tmp,tmp2;
    long long hoge = modinv(fac[b-1],MOD);
    long long fuga = modinv(fac[w-b-1],MOD);
    for(int i = 0;i<h-a;i++){
        tmp = fac[b+i-1];
        tmp*=hoge;
        tmp%=MOD;
        tmp*=modinv(fac[i],MOD);
        tmp%=MOD;
        tmp2 = fac[w+h-b-2-i];
        tmp2*=fuga;
        tmp2%=MOD;
        tmp2*=modinv(fac[h-i-1],MOD);
        tmp2%=MOD;
        ans+=((tmp*tmp2)%MOD);
        ans%=MOD;
    }
    cout << ans << endl;
}