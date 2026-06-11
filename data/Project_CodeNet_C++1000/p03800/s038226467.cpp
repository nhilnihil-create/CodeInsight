#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

string s;

bool ok(string& ans)
{
        string tmp(ans);
        tmp = ans.back() + tmp + ans.front();
        rep(i, 1, len(tmp)-1) {
                if (s[i-1] == 'o') {
                        if (tmp[i] == 'S') {
                                if (tmp[i-1] != tmp[i+1]) return false;
                        } else {
                                if (tmp[i-1] == tmp[i+1]) return false;
                        }
                } else {
                        if (tmp[i] == 'S') {
                                if (tmp[i-1] == tmp[i+1]) return false;
                        } else {
                                if (tmp[i-1] != tmp[i+1]) return false;
                        }                       
                }
        }
        return true;
}


int main()
{
        ll N;
        cin >> N >> s;
        string ans(N, 'X');


        rep(pattern, 0, 4) {

                fill(all(ans), 'X');
                if (pattern == 0) {
                        ans[0] = 'S';
                        ans[1] = 'S';
                } else if (pattern == 1) {
                        ans[0] = 'S';
                        ans[1] = 'W';
                } else if (pattern == 2) {
                        ans[0] = 'W';
                        ans[1] = 'S';
                } else {
                        ans[0] = 'W';
                        ans[1] = 'W';
                }

                rep(i, 1, N-1) {
                        char nowc = s[i];

                        char pani = ans[i-1];
                        
                        if (nowc == 'o') {
                                if (pani == 'S') {
                                        if (ans[i] == 'S') ans[i+1] = 'S';
                                        else ans[i+1] = 'W';
                                } else {
                                        if (ans[i] == 'S') ans[i+1] = 'W';
                                        else ans[i+1] = 'S';                                
                                }
                        } else {
                                if (pani == 'S') {
                                        if (ans[i] == 'S') ans[i+1] = 'W';
                                        else ans[i+1] = 'S';
                                } else {
                                        if (ans[i] == 'S') ans[i+1] = 'S';
                                        else ans[i+1] = 'W';                                
                                }                        
                        }
                }

                // cout << ans << endl;

                if (ok(ans)) {
                        cout << ans << endl;
                        return 0;
                }
        }
        cout << -1 << endl;
}