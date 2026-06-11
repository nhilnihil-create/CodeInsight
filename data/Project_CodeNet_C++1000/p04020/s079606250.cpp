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
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if(A[i] >= 2){
            ans += (A[i]-1)/2;
            A[i] = (A[i]+1)%2 + 1;
        }
    }

    for (ll i = 0; i < N-1; i++) {
        if(A[i] == 2){
            A[i] = 0;
            ans++;
        }
        else if(A[i]==1 && A[i+1]>=1){
            A[i]--; A[i+1]--;
            ans++;
        }
    }
    if(A[N-1]==2){
        ans++;
    }
    printf("%lld\n", ans);


}
