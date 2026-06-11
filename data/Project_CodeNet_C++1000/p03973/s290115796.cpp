#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};

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


    ll ans = a.front() - 1;
    ll maxval = 1;

    repf(i,1,n){
        // cout<<ans<<endl;
        if(a[i] == maxval+1){
            maxval++;
            continue;
        }

        if(a[i] > maxval){
            if(a[i]%(maxval+1) == 0) {a[i] -= maxval + 2; ans++;}
            ans += a[i]/(maxval+1);
        }else{
            continue;
        }

    }
    cout<<ans<<endl;


    return 0;

}