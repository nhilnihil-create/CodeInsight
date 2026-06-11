#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> C(N+1), D(N+1);
    C[0] = 0;
    D[0] = 0;
    for (int i = 1; i < N+1; i++) {
        D[i] = D[i-1] + A[i-1];
        if(A[i-1] >= 0){
            C[i] = C[i-1] + A[i-1];
        }
        else{
            C[i] = C[i-1];
        }
    }
    ll ans = 0;
    ll tmp;
    //i+1~i+K番目が白
    for (int i = 0; i < N-K+1; i++) {
        tmp = C[i] + C[N] - C[i+K];
        ans = max(ans, tmp);
    }
    //i+1~i+K番目が黒
    for (int i = 0; i < N-K+1; i++) {
        tmp = C[i] + C[N] - C[i+K] + D[i+K] - D[i];
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
    



}