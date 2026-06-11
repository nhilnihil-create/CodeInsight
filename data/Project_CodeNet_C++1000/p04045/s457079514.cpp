/* Simplicity and Goodness */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> indexed_set;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B)
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define rep(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int N = 2e5+2;


void solve()
{
    int n, k;
    scn(n); scn(k);

    set<int> dislikes;
    set<int> aval = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    rep(i, 0, k) {
        int val; 
        scn(val);
        dislikes.insert(val);
        aval.erase(val);
    }

    vector<char> digit = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool used = 0;
    string s = to_string(n);

    rep(i, 0, s.size()) {
        int here = s[i] - '0';
        if(used) {
            auto j = aval.begin();
            if(*j < here) {
                s[i] = digit[*j];
            }
            continue;
        }
        if(dislikes.count(here)) {
            auto j = aval.upper_bound(here);
            if(j == aval.end()) {
                j = aval.begin();
                s[i] = digit[*j];
                for(int j=i-1; j>=0; j--) {
                    auto it = aval.upper_bound(s[j]);
                    if(it == aval.end()) 
                        s[i] = digit[*aval.begin()];
                    else {
                        s[i] = digit[*it]; 
                        break;
                    }
                }
            } else {
                s[i] = digit[*j];
                used = 1;
            }
        }
    }

    string org = to_string(n);

    if(s < org) {
        auto it = aval.begin();
        s += digit[*it];
    }

    cout << s << '\n';
}

int main()
{
    int t = 1;
    // scn(t);
    
    while(t --) {
        solve();
    }
    return 0;
}