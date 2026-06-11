#include<bits/stdc++.h>
using namespace std;

const int MAX = 200001;
const int mod = 998244353;

long long fac[MAX], fac_inv_mod[MAX],inv_mod[MAX];

void comb_init(){
    fac[0] = fac[1] = 1;
    fac_inv_mod[0] = fac_inv_mod[1] = 1;
    inv_mod[1]=1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1] * i % mod;
        inv_mod[i] = mod - inv_mod[mod%i] * (mod / i) % mod;
        fac_inv_mod[i] = fac_inv_mod[i-1] * inv_mod[i] % mod;
    }
}

long long comb(int n, int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n] * (fac_inv_mod[k] * fac_inv_mod[n-k] % mod) % mod;
}

int main(){
    int n,p; cin>>n>>p;
    int even=0,odd=0;
    for(int i=0;i<n;i++){
        int c;cin>>c;
        if(c%2==0) even++;
        else odd ++;
    }
    long long ans = pow(2,even);
    comb_init();
    long long odds=0;
    if(p==1){
        for(int j=0; j<(odd+1)/1;j++){
            odds+=comb(odd,2*j+1);
        }
    }
    else{
        for(int j=0; j<=odd/2;j++){
            odds+=comb(odd,2*j);
        }
    }
    cout << ans*odds << endl;
}