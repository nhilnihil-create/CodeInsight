#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define long long long

vector<int> vec;

bool solve(){
  int n=vec.size();
  int odd=0;
  int even=0;
  int oi=-1;
  rep(i,n){
    if(vec[i]%2==0) even++;
    else oi=i,odd++;
  }
  if(even%2==1) return true;
  else if(even%2==0 && odd!=1) return false;
  else { // 偶数が偶数個，奇数が1個，全部偶数にして再チェック
    if(even==0) return false;
    if(vec[oi]==1) return false;
    vec[oi]--;
    int g=__gcd(vec[0], vec[1]);
    repl(i,2,n) g = __gcd(g, vec[i]);
    rep(i,n) vec[i]/=g;
    return !solve();
  }
}

int main(){
  int n;
  cin>>n;
  vec.resize(n);
  rep(i,n) cin>>vec[i];

  if(solve()) cout<<"First"<<endl;
  else cout<<"Second"<<endl;

  return 0;
}
