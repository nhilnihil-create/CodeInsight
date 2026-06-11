#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N;
    cin >> N;
    ll ans = 10;
    ll tmp1, tmp2;
    ll cnt1, cnt2;
    for (ll i = 1; i*i <= N; i++) {
        if(N % i == 0){
            tmp1 = i;
            tmp2 = N / i;
            cnt1 = 0; cnt2 = 0;
            while(tmp1 > 0){
                tmp1 = tmp1 / 10;
                cnt1++;
            }
            while(tmp2 > 0){
                tmp2 = tmp2 / 10;
                cnt2++;
            }
            ans = min(max(cnt1, cnt2), ans);
        }
    }
    printf("%lld\n", ans);

}