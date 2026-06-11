#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
using namespace std;
using Int = long long;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<55)+1e9; // ~ 3.6 * 1e16
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
using T = tuple<Int,Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
ostream& operator<<(ostream& o,T t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){Int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){Int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

Int calcEven(Int n){
  Int res = 0;
  for(Int i=1, sum = 2;i<=n;i++) res += sum, sum += 4;
  return res;
}

Int calcAllOdd(Int n){
  Int res = 1;
  for(Int i=1;i<n;i++) res += (i * 2 + 1);
  return res;
}

Int calc(vector<Int> Even, vector<Int> Odd){
  Int n = Even.size();
  Int m = Odd.size();

  if(Even.empty()) return calcAllOdd(m);
  
  Int b = 0;
  for(Int i=1;i<=m;i++) b += 1 + 2*i;
  for(Int i=1;i<n;i++) b += m * 2;
  return calcEven(n) + b;  
}

signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  Int n,m;
  cin>>n>>m;
  vector<vector<Int> > G(n);
  for(Int i=0;i<m;i++){
    Int u, v;
    cin>>u>>v; u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  if( m == 0 ){cout<<n * n <<endl; return 0;}

  vector<Int> Odd, Even;
  {
    vector<Int> used(n, -1);
    Int cnt, flag;
    function<void(Int,Int,Int)> dfs = [&](Int pos, Int pre,Int turn){
      if(used[pos] != -1){flag |= used[pos] != turn; return;}
      used[pos] = turn;
      cnt++;
      for(Int to:G[pos]) if(to != pre) dfs(to, pos, !turn);
    };
    
    for(Int i=0;i<n;i++){
      if(used[i] != -1) continue;
      cnt = flag = 0;
      dfs(i, -1, 0);
      flag == 0? Even.push_back(cnt):Odd.push_back(cnt);
    }
    sort(Odd.begin(), Odd.end());
    sort(Even.begin(), Even.end(),greater<Int>());
  }

  
  
  Int one = 0;
  while(!Even.empty() && Even.back() == 1) one++, Even.pop_back();

  Int ans = calc(Even, Odd);
  if(one) ans += 2 * n * one - one * one;
  cout<<ans<<endl;
  
  return 0;
}
