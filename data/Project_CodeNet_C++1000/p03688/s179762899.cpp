#include <bits/stdc++.h>
using namespace std;

typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;
typedef vector< vector< vector<ll> > > vvvint;
typedef vector<string> vstring;
typedef vector< vector<string> > vvstring;
typedef vector<char> vchar;
typedef vector< vector<char> > vvchar;
typedef vector<long double> vdouble;
typedef vector< vector<long double> > vvdouble;
typedef vector< vector< vector<long double> > > vvvdouble;
typedef pair<ll,ll> pint;
typedef vector<pint> vpint;
typedef vector<bool> vbool;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ALL(obj) (obj).begin(), (obj).end()
// #define LLONG_MAX 9223372036854775806
#define MOD 1000000007
const double PI=3.14159265358979323846;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T> T Ceil(T a, T b){return (a+b-1)/b;}

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};

void printv(vint &v){
    for(auto e:v) cout<<e<<" ";
        cout<<endl;
    }

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    cout<<fixed<<setprecision(10);


    ll n; cin>>n;
    vint a(n); rep(i,n) cin>>a[i];
    sort(ALL(a));

    map<ll,ll> m;
    for(auto e:a) m[e]++;

    if(m.size() > 2){
        puts("No");
        return 0;
    }else if(m.size() == 1){
        ll t1 = a.front();
        auto div1 = divisor(m[t1]);
        for(auto e:div1){
            if(e == m[t1]){
                if(e - 1 == t1){
                    puts("Yes");
                    return 0;
                }
            }else{
                if(e == t1){
                    puts("Yes");
                    return 0;
                }
            }
        }
        puts("No");
        return 0;
    }else{
        ll t1,t2;
        t1 = a.front();
        t2 = a.back();
        auto div1 = divisor(m[t1]);
        auto div2 = divisor(m[t2]);
        for(auto e1:div1){
            for(auto e2:div2){
                ll T = e1 + e2;
                // for t1
                bool b1 = T - (int)(e1==m[t1]) == t1;
                // for t2
                bool b2 = T - (int)(e2==m[t2]) == t2;
                if(b1&&b2){
                    puts("Yes");
                    return 0;
                }
            }
        }
        puts("No");
        return 0;
    }



    return 0;

}

