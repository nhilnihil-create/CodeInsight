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
    ll a,b,c;
    cin >> a >> b >> c;
    if(a%2==0 || b%2==0 || c%2==0) cout << 0 << endl;
    else cout << min({a*b,b*c,a*c}) << endl;
    return 0;
}