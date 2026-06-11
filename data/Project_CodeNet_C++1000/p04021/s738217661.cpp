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
    ll N; cin >> N;
    vector<llll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(ALL(A));

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        if(abs(A[i].second - i)%2 == 1){
            cnt++;
        }
    }
    printf("%lld\n", cnt/2);


    

}
