#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((int)1e6 + 3)
#define INF ((int)1e9)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (1 << (x))
using namespace std;

LL modinv(LL a){
    LL b = MOD, u = 1, v = 0;
    while(b){
        LL t = a / b;
        a -= t * b;swap(a, b);
        u -= t * v;swap(u, v);
    }
    u%=MOD;
    if(u < 0) u += MOD;
    return u;

}
int exp(int a, int b){
    LL res = 1;
    LL sum = a;
    for(int i=0;i<30;++i){
        if(BIT(i)&b){
            res = (res * sum)%MOD;
        }
        sum = (sum * sum) % MOD;
    }
    return res;
}

int main(){
    LL N, X;
    cin >> N >> X;
    N-=X;
    LL ans = 0;
    while(N!=0&&X!=0){
        if(N>=X){
            LL d = N / X;
            ans += d * X * 3;
            N %= X;
        }else{
            LL d = X / N;
            ans += d * N * 3;
            X %= N;
        }
    }
    cout << ans << endl;
    return 0;
}
