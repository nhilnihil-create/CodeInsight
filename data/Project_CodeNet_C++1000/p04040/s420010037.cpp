#include <iostream>
#include <vector>
using namespace std;
long long const mod = 1000000007;
long long mod_fact(int x){
    static vector<long long> fact = {1, 1};
    if(x < 0)return 0; //
    if(x < fact.size())return fact[x];
    for(int i = fact.size(); i <= x; i++){
        fact.push_back((fact[i-1] * i) % mod);
    }
    return fact[x];
}

long long mod_pow(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if(b%2 == 0){
            a = (a * a) % mod;
            b /= 2;
        }else{
            res = (res * a) % mod;
            b--;
        }
    }
    return res;
}

long long mod_comb(long long a, long long b){
    if(b < 0 || a < b)return 0;
    long long c = (mod_fact(a) * mod_pow(mod_fact(a-b), mod-2)) % mod;
    return (c * mod_pow(mod_fact(b), mod-2)) % mod;
}

int main(void){
    long long h, w, a, b, ans = 0;
    cin >> h >> w >> a >> b;
    for(int i=0;;i++){
        int y = h-a-i;
        int x = b+1+i;
        //cout << y << " " << x << endl;
        if(y < 1 || x > w)break;
        ans += (mod_comb(y+x-2, x-1) * mod_comb(h-y+w-x, h-y))%mod;
        ans %= mod;
        //cout << ans << endl;
    }
    cout << ans << endl;
}
