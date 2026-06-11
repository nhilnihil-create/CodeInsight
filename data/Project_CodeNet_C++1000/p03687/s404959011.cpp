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

bool ok(string s)
{
        rep(i, 0, len(s)) {
                char x = s[0];
                if (s[i] != x) return false;
        }
        return true;
}

int main()
{
        string S;
        cin >> S;
        ll N = len(S);

        map<char, ll> mp;
        rep(i, 0, N) mp[S[i]]++;
        vector<pair<ll, char> > rank;
        for (auto x : mp) {
                rank.emplace_back(pair<ll, char>{x.second, x.first});
        }
        sort(rank.rbegin(), rank.rend());

        ll ans = 0;
        ll ansans = inf;

        if (ok(S)) {
                cout << 0 << endl;
                return 0;
        }
        for (char alph = 'a'; alph <= 'z'; ++alph) {
                ans = 0;
                string prev(S);
                rep(i, 0, N) {
                        string s;

                        rep(j, 0, N-i-1) {
                                if (prev[j] == alph) s.push_back(prev[j]);
                                else if (prev[j+1] == alph) s.push_back(prev[j+1]);
                                else s.push_back(prev[j]);
                        } 
                        
                        ++ans;
                        if (ok(s)) break;
                        prev.clear();
                        rep(j, 0, len(s)) prev[j] = s[j];
                }
                chmin(ansans, ans);
        }

        cout << ansans << endl;
}