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
const int MAXN = 1e5+7;
char s[MAXN];
int n;

void solve(){
    scanf("%s",s+1);
    n = strlen(s + 1);
    vector<vi> vec(26,vi());
    for(int i = 1; i <= n; i++) vec[s[i]-'a'].pb(i);
    for(int i = 0; i < 26; i++){
        if(vec[i].size()<=1) continue;
        for(int p = 1; p < vec[i].size(); p++){
            if(vec[i][p]-vec[i][p-1]<=2){
                cout << vec[i][p-1] << ' ' << vec[i][p] << endl;
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("Local.in","r",stdin);
    freopen("ans.out","w",stdout);
    #endif
    solve();
    return 0;
}