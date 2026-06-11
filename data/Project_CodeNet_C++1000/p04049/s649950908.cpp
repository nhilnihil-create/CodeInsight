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

int N;
int K;
vector<vector<int> > road;

int count(int np, int lp, int deep){
    int res = 0;
    if(deep<0){
        ++res;
    }
    REP(i, road[np].size()){
        if(road[np][i]==lp)continue;
        res += count(road[np][i], np, deep-1);
    }
    return res;
}

int main(){
    cin >> N >> K;
    road.resize(N);
    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    int ans = INF;
    REP(i, N){
        if(K%2){
            REP(j, road[i].size()){
                ans = min(ans, count(road[i][j], i, K/2)+count(i, road[i][j], K/2));
            }
        }else{
            ans = min(ans, count(i, -1, K/2));
        }
    }
    cout << ans << endl;
    return 0;
}
