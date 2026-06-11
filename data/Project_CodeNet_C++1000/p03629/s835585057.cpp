#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)
#define Pr(a) (#a)<<"="<<(a)<<" "
#define pr1(a) cerr<<Pr(a)<<endl
#define pr2(a,b) cerr<<Pr(a)<<Pr(b)<<endl
#define pr3(a,b,c) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<endl
#define pr4(a,b,c,d) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<endl
#define pr5(a,b,c,d,e) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<endl
#define pr6(a,b,c,d,e,f) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<Pr(f)<<endl
#define int long long
#define double long double
using namespace std;
const int INF = 1LL<<55;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
typedef pair<int,int> P;
typedef long long ll;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}


void chmin(string &a,string b){
  if(a[0] == '!'){
    a = b;
    return;
  }
  
  if(a.size() != b.size()){
    if( a.size() > b.size() ) a = b;
    return;
  }
  if(a > b) a = b;
}

int n;
string s;
vector<int> Idx[26];

int dfs(int idx){
  static int mem[200010];
  static int used[200010]={};
  if(idx == n) return 0;
  if(idx >= 0 && used[idx]++) return mem[idx];
  
  int res =1e9;
  for(int i=0;i<26;i++){
    int to = (*upper_bound(Idx[i].begin(), Idx[i].end(), idx));
    Min(res, (1 + dfs(to)));
  }
  if(idx == -1) return res;
  return mem[idx] = res;
}

string dfs2(int idx){
  if(idx == n) return "";
  
  typedef tuple<int,int,int> T;
  vector<T> To;
  for(int i=0;i<26;i++){
    char ch = 'a' + i;
    int to = (*upper_bound(Idx[i].begin(), Idx[i].end(), idx));
    To.push_back(T(dfs(to), ch, to));
  }
  
  sort(To.begin(),To.end());
  int len, ch, to; tie(len, ch, to) = To[0];
  return (char)ch + dfs2(to);
}


signed main(){
  //cin.tie(0);
  //ios_base::sync_with_stdio(0);
  //cout << fixed << setprecision(12);
  srand((unsigned) time(NULL));

  cin>>s;
  n = s.size();

  for(int i=0;i<n;i++) Idx[s[i] - 'a'].push_back(i);
  for(int i=0;i<26;i++) Idx[i].push_back(n);

  string ans = dfs2(-1);
  cout<<ans<<endl;
  return 0;
}
