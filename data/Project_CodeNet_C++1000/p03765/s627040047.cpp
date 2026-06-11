#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S, T;
  cin>>S>>T;
  int Sarr[S.size()+1], Tarr[T.size()+1];
  for(int i=0;i<=S.size();++i) Sarr[i] = 0;
  for(int i=0;i<=T.size();++i) Tarr[i] = 0;
  for(int i=0;i<S.size();++i) {
    if(S[i]=='A') Sarr[i+1] = 1;
    else Sarr[i+1] = 2;
  }
  for(int i=0;i<T.size();++i) {
    if(T[i]=='A') Tarr[i+1] = 1;
    else Tarr[i+1] = 2;
  }
  for(int i=1;i<=S.size();++i) Sarr[i] += Sarr[i-1];
  for(int i=1;i<=T.size();++i) Tarr[i] += Tarr[i-1];
  int Q;
  cin>>Q;
  bool ans[Q];
  int a, b, c, d;
  for(int i=0;i<Q;++i) {
    cin>>a>>b>>c>>d;
    if(((Sarr[b]-Sarr[a-1])-(Tarr[d]-Tarr[c-1]))%3==0) ans[i] = true;
    else ans[i] = false;
  }
  for(int i=0;i<Q;++i) {
    if(ans[i]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}

