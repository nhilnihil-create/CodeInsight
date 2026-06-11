#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    ll a = 1,b = 1;
    rep(i,n){
        ll c,d;
        cin >> c >> d;
        ll N = max((a+c-1)/c,(b+d-1)/d);
        a = c * N;
        b = d * N;
        //cout << a << " " << b << endl;
    }
    cout << a + b << endl;
}