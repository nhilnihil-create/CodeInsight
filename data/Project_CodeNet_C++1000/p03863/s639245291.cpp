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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  bool muri = true;
  for(int i=0;i<S.size();++i) {
    if(i+2>=S.size()) break;
    if(S[i]!=S[i+2]) muri = false;
  }
  if(muri) cout<<"Second"<<endl;
  else {
    if(S[0]==S[S.size()-1]) {
      if(S.size()%2!=0) cout<<"Second"<<endl;
      else cout<<"First"<<endl;
    }
    else {
      if(S.size()%2==0) cout<<"Second"<<endl;
      else cout<<"First"<<endl;
    }
  }
}
