#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  string s;
  cin>>s; 
  int n=s.size();
  vector<bool>al(26);
  rep(i,n){
    al[s[i]-'a']=true;
  }
  int ans=1001001;
  rep(i,26){
    char c='a'+i;
    if(al[i]){
      int co=-1;
      int dif;
      int ch=0;
      rep(j,n){
        if(s[j]==c){
          dif=j-co;
          co=j;
          ch=max(ch,dif-1);
        }
      }
      ch=max(n-co-1,ch);
      ans=min(ans,ch);
    }
  }
  cout<<ans<<endl;
}