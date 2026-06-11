#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  string S;
  cin>>S;
  vector<ll> X(26);
  rep(i,S.size()) X[S[i]-'a']++;
  ll ans=S.size()*(S.size()-1)/2+1;
  rep(i,26) ans-=X[i]*(X[i]-1)/2;
  cout<<ans<<endl;
}