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
    ll N, L;
    cin >> N >> L;
    vector<ll> A(N);

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll c = -1;
    for (ll i = 0; i < N-1; i++) {
        if(A[i] + A[i+1] >= L){
            c = i;
        }
    }
    if(c == -1){
        printf("Impossible\n");
    }
    else{
        printf("Possible\n");
        c++;
        for (ll i = 1; i < c; i++) {
            printf("%lld\n", i);
        }
        for (ll i = N-1; i >= c; i--) {
            printf("%lld\n", i);
        }

    }

}