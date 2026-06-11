#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> pos[26];
ll t[200005]={0};
ll ch[200005]={0},zk[200005]={0};
ll nxt(ll i,ll c){
  ll ps=upper_bound(pos[c].begin(),pos[c].end(),i)-pos[c].begin();
  if(ps==pos[c].size()) return 200004;
  else return pos[c][ps];
}
int main(){
  string s=".",ks;
  cin>>ks;
  s+=ks;
  ll n=ks.length();
  for(int i=1;i<=n;i++){
    int j=s[i]-'a';
    pos[j].push_back(i);
  }
  for(int i=n;i>=0;i--){
    t[i]=174417441744;
    for(int j=0;j<26;j++){
      ll ni=nxt(i,j);
      if(t[i]>t[ni]+1){
        t[i]=t[ni]+1;
        ch[i]=ni;
        zk[i]=j;
      }
    }
  }
  string ans;
  ll ps=0;
  for(int i=0;i<t[0];i++) {
    ans.push_back((char)(zk[ps]+'a'));
    ps=ch[ps];
  }
  cout<<ans<<endl;
}
