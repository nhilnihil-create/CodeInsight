#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e6+5;
typedef long long ll;
int f[maxn];

int up(int a,int b){
    a+=b;
    if(a>=mod) a-=mod;
    return a;
}

int mul(ll  a, ll  b){
    return ((a%mod) *(b%mod)) % mod;
}

int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    f[1] = n;f[2] = mul(n,n);
    
    for(int i = 3; i <= n; i++){
        f[i] = up(f[i-1],sum);
        f[i] = up(f[i],mul(n-1,n-1));
        f[i] = up(f[i],n-i+2);
        sum = up(sum,f[i-2]);
    }
    printf("%d\n", f[n]);
    return 0;
}