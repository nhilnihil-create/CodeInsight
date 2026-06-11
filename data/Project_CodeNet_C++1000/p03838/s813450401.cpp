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
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll x, y;
    cin >> x >> y;
    ll ans;
    if(x == 0){
        ans = abs(y);
        if(y < 0){
            ans++;
        }
    }
    else if(y == 0){
        ans = abs(x);
        if(x > 0){
            ans++;
        }
    }
    else{
        ans = abs(abs(x) - abs(y));
        if((x > 0) ^ (y > 0)){
            ans++;
        }
        else{
            if( x > 0 && y < x ){
                ans += 2;
            }
            else if( x < 0 && y < x ){
                ans += 2;
            }
        }
    }

    printf("%lld\n", ans);
}