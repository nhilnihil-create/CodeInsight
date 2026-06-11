
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;


int main(){
  int i,j;
  string s;
  cin>>s;
  int n=s.size();
  VI v(26,0);
  VI w(n);
  int cnt=1;
  int t=0;
  for(i=n-1;i>=0;i--){
    if(v[s[i]-'a']==0) {
      v[s[i]-'a']=1;
      t++;
    }
    w[i]=cnt;
    if(t==26){
      t=0;
      v=VI(26,0);
      cnt++;
    }
  }
  
  string ans="";
  int po=0;
  while(1){
    v=VI(26,0);
    while(po<n&&w[po]==cnt){
      v[s[po]-'a']=1;
      po++;
    }
    for(i=0;i<26;i++){
      if(v[i]==0){
        ans+=i+'a';
        cnt--;
        break;
      }
    }
    if(cnt==0) break;
    while(po<n&&s[po]!=ans[ans.size()-1]){
      po++;
    }
    po++;
  }
  cout<<ans<<endl;

}
