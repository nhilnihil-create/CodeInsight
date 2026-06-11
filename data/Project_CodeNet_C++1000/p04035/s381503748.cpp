#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,L;
  cin>>N>>L;
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a[i];

  int memo=-1;
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]>=L)memo=i;
  }
/*{{{*/
  if(memo==-1){
    cout<<"Impossible"<<endl;
    return 0;
  }
/*}}}*/

  vector<int>ans;
  ans.push_back(memo);
  for(int i=memo+1;i<N-1;i++)ans.push_back(i);
  for(int i=memo-1;i>=0;i--)ans.push_back(i);
  reverse(rng(ans));
  cout<<"Possible"<<endl;
  for(auto it:ans)cout<<it+1<<endl;

  return 0;
}
