#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)
#define Pr(a) (#a)<<"="<<(a)<<" "
#define pr1(a) cerr<<Pr(a)<<endl;
#define pr2(a,b) cerr<<Pr(a)<<Pr(b)<<endl;
#define pr3(a,b,c) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<endl;
#define pr4(a,b,c,d) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<endl;
#define pr5(a,b,c,d,e) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<endl;
#define pr6(a,b,c,d,e,f) cerr<<Pr(a)<<Pr(b)<<Pr(c)<<Pr(d)<<Pr(e)<<Pr(f)<<endl;
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


vector<int> calc(vector<int> a,vector<int> b){
  int n = a.size();
  vector<int> c(n);
  for(int i=0;i<n;i++) c[i] = b[a[i]];
  return c;
}

vector<int> doubling(vector<int> idx,int K){
  int n = idx.size();
  vector<int> res(n);
  for(int i=0;i<n;i++) res[i] = i;
  while(K){
    if(K%2) res = calc(res, idx);
    idx = calc(idx, idx);
    K/=2;
  }
  return res;
}

signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n;
  cin>>n;
  vector<int> X(n);
  cin>>X;
  
  int m, K;
  cin>>m>>K;
  vector<int> A(m);
  cin>>A;

  vector<int> sa(n-1);
  for(int i=0;i<n-1;i++) sa[i] = X[i+1] - X[i];

  vector<int> idx(n-1);
  for(int i=0;i<n-1;i++) idx[i] = i;
  for(int i=0;i<m;i++){
    int a = A[i] - 1;
    swap(idx[a], idx[a-1]);
  }

  idx = doubling(idx,K);
  vector<int> ans(n);
  ans[0] = X[0];
  ans[n-1] = X[n-1];

  for(int i=1;i<n;i++) ans[i] = ans[i-1] + sa[idx[i-1]];
  for(double a:ans) cout<<a<<endl;
  return 0;
}
