#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
typedef pair<ll,ll> P;

int next(int pre,int now,const char&c){
    int res;
    if(!now){
        if(c=='o')res=pre;
        else res=pre^1;
    }
    else {
        if(c=='o')res=pre^1;
        else res=pre;
    }
    return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin>>n>>s;
  rep(i,2)rep(j,2){
      int pre=i;
      int now=j;
      map<int,string> mp;
      mp[0]='S';
      mp[1]='W';
      string ans=mp[i]+mp[j];
      rep(k,n-1){
          pre=next(pre,now,s[k+1]);
          if(k!=n-2)ans+=mp[pre];
          swap(pre,now);
      }
      if(now==i&&next(pre,now,s[0])==j){
          cout<<ans<<endl;
          return 0;
      }
  }
  cout<<-1<<endl;
  return 0;
  }
