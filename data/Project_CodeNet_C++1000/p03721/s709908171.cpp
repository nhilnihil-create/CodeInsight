#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))


int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<ll,ll>>A(N);
    vector<ll>rui(N+1);

    rui.at(0) = 0;
    for(ll i = 0;i < N;i++){
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(),A.end());

    for(ll i = 0;i < N;i++){
        rui.at(i+1) = A[i].second + rui.at(i);
    }

    const ll j = lower_bound(ALL(rui),K) - 1 - rui.begin();

    cout << A[j].first << endl;

    return 0;

}