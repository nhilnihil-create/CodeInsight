#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=1000005;
const ll INF=0x3f3f3f3f3f3f3f;
const ll MOD=1000000007;
ll n;
int main(){
    scanf("%lld",&n);
    for(ll i=0;;i++){
        if(i*(i+1)/2>=n){
            printf("%lld\n",i);
            return 0;
        }
    }
}
