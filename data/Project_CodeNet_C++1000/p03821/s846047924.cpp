#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>


#define INF             1e9
#define INFL            8e18
#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise " << __LINE__ << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define READ            freopen("D:\\moidda CPP\\alu.txt", "r", stdin)
#define WRITE           freopen("D:\\moidda CPP\\vorta.txt", "w", stdout)
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MASK(x)         for(int i = 0; i < 8; i++){ if(x&(1<<i)){ cout << i << " "; } } cout << endl;

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pff;

const int MAX = 1e3 + 2;
const int MAXLOG = log2(MAX) + 2;
const int MAX_VALUE = 200 + 2;
const int MOD = 1e9 + 7;
const double PY = acos(-1.0);
const double EPS = 1E-9;

int32_t main()
{
//#ifndef ONLINE_JUDGE
//    READ;
//    WRITE;
//#endif

    FASTIO;

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    ll sum = 0;
    for(int i = n-1; i >= 0; i--){
        a[i] += sum;
        ll x = ceil((double)a[i]/b[i])*b[i];
        sum += x-a[i];
    }
    cout << sum;

    return 0;
}
