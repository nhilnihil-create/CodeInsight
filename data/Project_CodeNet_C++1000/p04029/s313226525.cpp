#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long int
#define vi vector<int>
#define vl vector<LL>
#define pb push_back
#define all(V) V.begin(),V.end()
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%I64d",&x)
#define pii pair<int,int>
#define cmax(a,b) ((a) = (a) > (b) ? (a) : (b))
#define cmin(a,b) ((a) = (a) < (b) ? (a) : (b))
#define debug(x)  cerr << #x << " = " << x << endl
function<void(void)> ____ = [](){ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};

void solve(){
    LL a; cin >> a;
    cout << (a) * (a + 1) / 2 << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Local.in","r",stdin);
    freopen("ans.out","w",stdout);
    #endif
    solve();
    return 0;
}