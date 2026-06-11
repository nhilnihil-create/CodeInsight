#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

const int MxN=1e3+5;
const int MOD=1e9+7;
ve<ull> primes;

void sieve(int n) {
    ve<bool> a(n+1, 1);
    for(int i=2;i*i<=n;i++)
        if(a[i])
            for(int j=i*2;j<=n;j+=i)
                a[j]=0;
    for(int i=2;i<=n;i++)
        if(a[i]) primes.push_back(i);
}

int main() {
    int n;cin>>n;
    sieve(n);
    ull res=1;
    rep(i,0,primes.size()) {
        // current divisor
        ull p=primes[i];
        // highest power of current prime that divides n
        ull e=0;
        // legendre's formula
        while(p<=n) {
            e+=(n/p);
            p*=primes[i];
            p%=MOD;
        }
        res*=e+1;
        res%=MOD;
    }
    cout<<res%MOD<<endl;
    return 0;
}