#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a.at(i);
    ll tmp, ans;
    ll tmpsum;

    //1つめが負
    tmp = 0;
    tmpsum = 0;
    for (int i = 0; i < N; i++) {
        tmpsum += a[i];
        if(i % 2 == 0){
            if(tmpsum < 0) continue;
            tmp += tmpsum + 1;
            tmpsum = -1;
        }
        else{
            if(tmpsum > 0) continue;
            tmp += 1 - tmpsum;
            tmpsum = 1;
        }
    }
    ans = tmp;

    //1つめが正
    tmp = 0;
    tmpsum = 0;
    for (int i = 0; i < N; i++) {
        tmpsum += a[i];
        if(i % 2 == 1){
            if(tmpsum < 0) continue;
            tmp += tmpsum + 1;
            tmpsum = -1;
        }
        else{
            if(tmpsum > 0) continue;
            tmp += 1 - tmpsum;
            tmpsum = 1;
        }
    }
    ans = min(tmp, ans);

    printf("%lld\n", ans);



}
