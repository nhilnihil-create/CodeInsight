#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int a,b,c,d,e,f;
  cin >>a>>b>>c>>d>>e>>f;
  P ans=P(100*a,0);
  P co=P(1,0);
  vector<int>s,w;
  rep(i,f+1){
    rep(j,f+1){
      int now=c*i+d*j;
      if(now<f){
        s.push_back(now);
      }
    }
  }
  rep(i,f+1){
    rep(j,f+1){
      int now=100*a*i+100*b*j;
      if(0<now&&now<=f){
        w.push_back(now);
      }
    }
  }
  rep(i,s.size()){
    rep(j,w.size()){
      if(s[i]+w[j]<=f&&s[i]*100<=w[j]*e){
        if(co.second*w[j]<co.first*s[i]){
          ans=P(w[j],s[i]);
          co=P(w[j],s[i]);
        }
      }
    }
  }
        
      
  cout<<ans.first+ans.second<<" "<<ans.second<<endl;
}