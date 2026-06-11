#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define per(i,j,n) for(int i=(int)(j);(int)(n)<=i;i--)
#define int long long
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<vi>
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=(1ll<<62)-1;
signed main(){
  string S; cin>>S;
  set<char> M;
  rep(i,0,S.size()){
    M.insert(S[i]);
  }
  string ans="Yes";
  if((M.count('N')^M.count('S'))) ans="No";
  if((M.count('W')^M.count('E'))) ans="No";
  cout<<ans<<endl;
}