#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll choose(int n, int a){
  ll res = 1;
  vector<int>num;
  for(int i=2; i<=a; ++i){
    num.push_back(i);
  }
  for(int i = 0; i < a; ++i){
    res *= n-i;
    rep(j,num.size()){
      if(num[j] == -1)continue;
      if(res % num[j] == 0){
        res /= num[j];
        num[j] = -1;
      }
    }
  }
  return res;
}

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<ll>v(n);
  map<ll,int>mp;
  rep(i,n){
    cin>>v[i];
    mp[v[i]]++;
  }
  sort(v.rbegin(),v.rend());

  double num=0;
  rep(i,a){
    num+=v[i]/(1.0*a);
  }

  bool go=false;
  ll ans=0;

  for(int i=a; i<=b; ++i){
    ll res=1;

    if(i!=n){
      set<ll>judge;
      rep(j,i+1)judge.insert(v[j]);
      if(judge.size()>=2)go=true;
    }

    map<ll,int>mpcnt;
    rep(j,i)mpcnt[v[j]]++;
    for(auto p:mpcnt){
      res*=choose(mp[p.first],p.second);
    }
    ans+=res;
    
    if(go)break;
  }
  printf("%.10f\n%lld\n",num,ans);
}