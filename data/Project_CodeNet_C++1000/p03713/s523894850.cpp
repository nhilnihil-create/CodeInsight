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
        ll H, W;
        cin >> H >> W;

        ll ans = inf;
        rep(h, 1, H+1) {
                ll s1 = h * W;
                ll h1 = (H-h) / 2;
                ll h2 = h1;
                if ((H-h) % 2 != 0) ++h2;
                ll s2 = h1 * W;
                ll s3 = h2 * W;
                if ((H-h) % 2 != 0) ++s3;
                ll smax = max(s1, max(s2, s3));
                ll smin = min(s1, min(s2, s3));
                chmin(ans, smax-smin);

                ll w1 = W / 2;
                ll w2 = w1;
                if (W % 2 != 0) ++w2;
                s2 = w1 * (H-h);
                s3 = w2 * (H-h);
                smax = max(s1, max(s2, s3));
                smin = min(s1, min(s2, s3));
                chmin(ans, smax-smin);               


        }

        swap(H, W);
        rep(h, 1, H+1) {
                ll s1 = h * W;
                ll h1 = (H-h) / 2;
                ll h2 = h1;
                if ((H-h) % 2 != 0) ++h2;
                ll s2 = h1 * W;
                ll s3 = h2 * W;
                if ((H-h) % 2 != 0) ++s3;
                ll smax = max(s1, max(s2, s3));
                ll smin = min(s1, min(s2, s3));
                chmin(ans, smax-smin);

                ll w1 = W / 2;
                ll w2 = w1;
                if (W % 2 != 0) ++w2;
                s2 = w1 * (H-h);
                s3 = w2 * (H-h);
                smax = max(s1, max(s2, s3));
                smin = min(s1, min(s2, s3));
                chmin(ans, smax-smin);               


        }

        cout << ans << endl;
}




