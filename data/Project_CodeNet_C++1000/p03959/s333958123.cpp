#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll,ll> pll;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define MOD 1000000007
#define ARRAY_MAX 200005

const int INF = 1e9+7;



int main(){

    ll n;
    cin >> n;
    vector<ll> a(ARRAY_MAX,0),t(ARRAY_MAX,0);

    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> t[i];
    }
    ll ans = 1;
    for(int i = 1;i <= n;i++){

        if((a[i-1] < a[i] && t[i] < a[i]) || (t[i] > t[i+1] && t[i] > a[i])){//矛盾しているケース
            ans = 0;
        }else if(a[i-1] == a[i] && t[i] == t[i+1]){//高さは任意の部分(最小の高さを取ればいい)
            ans *= min(a[i],t[i]);
            ans %= MOD;
        }
    }
    cout << ans << endl;



    return 0;
}