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
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

bool ask(long n){
  cout << "? " << n << endl;
  string ans;

  // {
  //   long N = 9999;
  //   string sN = to_string(N);
  //   string sn = to_string(n);
  //   return (n<=N && sn<=sN) || (n>N && sn>sN);
  // }

  cin>>ans;
  return ans=="Y";
}

int main(){
  long dig = 1;

const long XX = 10000000000LL;
  while(dig <= XX && ask(dig)) dig *= 10L;
  dig /= 10;

  if(dig == XX){
    dig = 1;
    while(!ask(dig*10 - 1)) dig *= 10;

    cout << "! " << dig << endl;
    return 0;
  }

  long l = dig, r = dig*10;
  while(r-l>1){
    long m = (r+l)/2;
    if(ask(m*10)) r = m;
    else l = m;
  }

  cout << "! " << r << endl;

  return 0;
}
