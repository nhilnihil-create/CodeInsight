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
#define vmax(vec) *max_element(vec.begin(), vec.end())
#define vmin(vec) *min_element(vec.begin(), vec.end())
#define vsort(vec) sort(vec.begin(), vec.end())
#define vsortgr(vec) sort(vec.begin(), vec.end(), greater<ll>())
#define MOD 1000000007
const double PI=3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void print(const vint& v)
{
  for(auto e:v)cout<<e<<" ";
  cout<<endl;
}

int cnt[1000];

void show(vint &v){
  if(v.size()==1){
    // print(v);
    cnt[v[0]]++;
    return;
  }
  vint nxt(v.size()-2);
  rep(i,nxt.size()){
    vint tmp(3);
    repf(j,i,i+3){
      tmp[j-i] = v[j];
    }
    sort(ALL(tmp));
    nxt[i] = tmp[1];
  }

  show(nxt);
  // print(v);
  return;

}

int main() {


  cout<<fixed<<setprecision(10);

  ll n,x; cin>>n>>x;

  if(x==1 || x==2*n-1){
    puts("No");
  }else{
    puts("Yes");
    vint ans(2*n-1, -1);
    ans[n-1] = x;
    ans[n] = 2*n-1;
    ans[n-2] = 1;
    
    queue<ll> q;
    repf(i,2,x) q.push(i);
    repf(i,x+1,2*n-1) q.push(i);

    rep(i, n-2){
      ans[i] = q.front(); q.pop();
    }
    repf(i, n+1, 2*n-1){
      ans[i] = q.front(); q.pop();
    }

    for(auto e:ans) cout<<e<<endl;
  }

}
//
