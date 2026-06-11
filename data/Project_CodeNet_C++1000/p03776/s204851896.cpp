//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    vector<vector<ll>> c(51, vector<ll>(51));
    for(int i = 0; i <= 50; i++) c[i][0] = 1, c[i][i] = 1;
    for(int i = 1; i <= 50; i++){
        for(int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }


    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    map<ll, int> cnt;
    for(int i = 0; i < n; i++) cin >> v[i], cnt[v[i]]++;
    gsort(v);

    if(v[0] != v[a - 1]){
        ld sum = 0;
        for(int i = 0; i < a; i++) sum += v[i];
        cout << fixed << setprecision(20) << sum / a << "\n";
        int tmp = 0;
        for(int i = 0; i < a; i++) if(v[i] == v[a - 1]) tmp++;
        cout << c[cnt[v[a - 1]]][tmp] << "\n";
    }
    else{
        cout << v[0] << "\n";
        ll ans = 0;
        for(int i = a; i <= b; i++) ans += c[cnt[v[a - 1]]][i];
        cout << ans << "\n";
    }

    return 0;
}