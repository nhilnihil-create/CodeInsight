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
  string S;
  cin>>S;
  int N=S.size();
  ll K;
  cin>>K;
  for(int i=0;i<N;++i) {
    if(S[i]=='a') continue;
    if(K>='z'-S[i]+1) {
      K -= 'z'-S[i]+1;
      S[i] = 'a';
    }
  }
  K %= 26;
  if(S[N-1]+K>'z') {
    S[N-1] = S[N-1]-'z'+'a'-1;
  }
  else S[N-1] += K;
  cout<<S<<endl;
}

