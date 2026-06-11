#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;}
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;



int main()
{
        ll N;
        cin >> N;
        vll a(N);
        rep(i, 0, N) cin >> a[i];

        vll acc(N+1);
        rep(i, 1, N+1) {
                acc[i] += acc[i-1] + a[i-1];
        }

        ll now = 0;
        ll cnt1 = 0;
        for (int i = 1; i <=N; ++i) {
                if (odd(i)) {
                        if (now + acc[i] <= 0) {
                                cnt1 += abs(1 - (now + acc[i]));
                                now += 1 - (now + acc[i]);
                        }
                } else {
                        if (now + acc[i] >= 0) {
                                cnt1 += abs(-1 - (now + acc[i]));
                                now += -1 - (now + acc[i]);
                        }
                }
        }

        now = 0;
        ll cnt2 = 0;
        for (int i = 1; i <=N; ++i) {
                if (even(i)) {
                        if (now + acc[i] <= 0) {
                                cnt2 += abs(1 - (now + acc[i]));
                                now += 1 - (now + acc[i]);
                        }
                } else {
                        if (now + acc[i] >= 0) {
                                cnt2 += abs(-1 - (now + acc[i]));
                                now += -1 - (now + acc[i]);
                        }
                }
        }

        cout << min(cnt1, cnt2) << endl;
}