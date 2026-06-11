#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    ll nowt,nowa;
    rep(i,n){
        ll t,a;
        cin >> t >> a;
        if(i == 0){
            nowt = t;
            nowa = a;
        }else{
            ll n1 = (t+nowt-1)/t, n2 = (a+nowa-1)/a;
            n1 = max(n1,n2);
            n2 = max(n1,n2);
            nowt = n1 * t;
            nowa = n2 * a;
        }
    }
    cout << nowt + nowa << endl;
    return 0;
}