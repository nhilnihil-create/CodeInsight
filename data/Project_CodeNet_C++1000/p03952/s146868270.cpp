#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repr(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define print(x) cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll countDigit(ll n) { return floor(log10(n) + 1); } 
typedef pair <ll,ll> P;
static const ll dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";  
    return os; 
}

template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& m) 
{ 
    for (auto p : m) os << "<" << p.first << ", " << p.second << "> "; 
    return os; 
}

int main()
{
    ll N, x;
    cin >> N >> x;
    if (x == 2*N-1 || x == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if (N == 2) {
            rep(i, 2*N-1) print(i+1);
        } else {
            vector<ll> ans(2*N-1);
            if (x < 2*N-2) {
                ans[N-1] = x;
                ans[N-2] = x+1;
                ans[N] = x-1;
                ans[N+1] = x+2;
                ll cnt = 1;
                rep(i, 2*N-1) {
                    if (i < N-2 || N+1 < i) {
                        if (cnt == x-1) cnt += 4;
                        ans[i] = cnt;
                        cnt++;
                    }
                }
            } else {
                ans[N-1] = x;
                ans[N-2] = x-1;
                ans[N] = x+1;
                ans[N+1] = x-2;
                ll cnt = 1;
                rep(i, 2*N-1) {
                    if (i < N-2 || N+1 < i) {
                        if (cnt == x-2) cnt += 4;
                        ans[i] = cnt;
                        cnt++;
                    }
                }
            }
            
            rep(i, 2*N-1) print(ans[i]);
        }
    }
    return 0;
} 