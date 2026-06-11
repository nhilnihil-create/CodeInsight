#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

string str(ll n){
  stringstream ss;
  ss << n;
  return ss.str();
}

int N;
bool snuke(ll n){
  if(n<=N && str(n)<=str(N))return true;
  if(n>N && str(n)>str(N))return true;
  return false;
}

int qcnt = 0;
bool query(ll n){
  if(n < 1 || n > 1000000000000000000ll){
    cout << "ERROR" << n << endl;
    exit(1);
  }
  qcnt++;
  if(false){
    return snuke(n);
  }else{
    cout << "? " << n << endl;
    string ans;
    cin >> ans;
    return ans == "Y";
  }
}

int main(){
  // FOR(i,1,1252){
  //   N = i;
  //   cout << (snuke(1)?"1":"0");
  //   cout << (snuke(9)?"1":"0");
  //   cout << " ";
  //   cout << (snuke(10)?"1":"0");
  //   cout << (snuke(99)?"1":"0");
  //   cout << " ";
  //   cout << (snuke(100)?"1":"0");
  //   cout << (snuke(999)?"1":"0");
  //   cout << " ";
  //   cout << (snuke(1000)?"1":"0");
  //   cout << (snuke(9999)?"1":"0");
  //   cout << " ";
  //   cout << (snuke(10000)?"1":"0");
  //   cout << (snuke(99999)?"1":"0");
  //   cout << endl;
  // }
  // N = 525;
  // // cout<<" "<<endl;
  // FOR(i,0,999){
  //   cout << (snuke(i)?"1":"0");
  //   if(i%10==9)cout<<endl;
  // }
  // cout << endl;
  const ll e9 = 1000000000ll;
  // cin>>N;
  // N = 123;
  // N = 1;
  // FOR(i,1,1000){
  //   if(i==1)cout<<" ";
  //   cout<<query(i);
  //   if(i%10==9)cout<<endl;
  // }
  // return 0;
  // decide
  ll ans = 0;
  ll bai = e9 * e9 / 10ll;
  REP(i,10){
    ans *= 10;
    int low = 0, high = 10;
    // if(i==0)low++;
    while(low+1<high){
      int x = (low+high)/2;
      ll q = ans + x;
      bool po = query(bai * (ans+x));
      if(po){
        high = x;
      }else{
        low = x;
      }
    }
    ans += low;
    if(ans>0)bai /= 10ll;
  }
  if(ans==0){
    ans = e9;
  }else{
    ans ++;
  }
  // cout << ans << endl;
  while(ans % 10 == 0){
    ll nxt = ans/10+1;
    if(str(nxt).size() == str(ans).size()){
      // 99999
      if(query(nxt)){
        break;
      }else{
        ans /= 10;
        break;
      }
    }
    if(query(ans/10+1)){
      ans /= 10;
    }else{
      break;
    }
  }
  // cout << qcnt << endl;
  cout << "! " << ans << endl;
  return 0;
}
