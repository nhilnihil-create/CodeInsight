#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")
#define FOR(i,j,n) for (int i=(j);i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REPN(i,n) for (int i=(n);i>=0;i--)
#define I(n) scanf("%d", &(n))
#define pb(n) push_back((n))
#define mp(i,j) make_pair((i),(j))
#include <bits/stdc++.h>
using namespace std;

//------------------------------typedef集
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef vector<vvi> vvvi;
typedef long long ll;

int n,k,a[100010],b[100010];
ll ret,tmp;
vi tgt;

int main(){
    I(n); I(k);
    tgt.pb(k);
    REP(i,30){
        int kouho = (k >> i) << i;
        kouho += ((1 >> i) - 1);
        if (kouho > 0 && kouho <= k) tgt.pb(kouho);
    }
    REP(i,n) { I(a[i]); I(b[i]); }
    for (auto mask : tgt){
        tmp = 0;
        REP(i,n) if ((mask | a[i]) == mask) tmp += b[i];
        ret = max(ret,tmp);
    }
    cout << ret << endl;
}
