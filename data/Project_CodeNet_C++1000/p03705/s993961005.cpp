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
    ll N,A,B;
    cin >> N >> A >> B;
    if(N==1){
        if(A==B){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    else if( A > B ){
        printf("0\n");
    }
    else{
        printf("%lld\n", (N-2)*(B-A)+1);
    }

}
