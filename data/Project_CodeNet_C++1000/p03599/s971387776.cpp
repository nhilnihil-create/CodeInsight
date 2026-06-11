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
#define int ll

double getper(int a,int b){
  return 1.*(100*b)/(a+b);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A,B,C,D,E,F;
  cin>>A>>B>>C>>D>>E>>F;
  vector<int>AB;
  for(int i=0;i*A*100<=F;i++){
    for(int j=0;j*B*100<=F;j++){
      if(i*A+j*B>F)continue;
      if(i==0&&j==0)continue;
      AB.push_back(i*A+j*B);
    }
  }
  sort(rng(AB));
  ll ansAB=0;
  ll ansCD=0;
  double per=0;
  for(int i=0;i<=3000;i++){
    for(int j=0;j<=3000;j++){
      int CD=i*C+j*D;
      auto it=lower_bound(rng(AB),1.*CD/E);
      if(it==AB.end())continue;
      if(*it*100+CD>F)continue;
      if(per<=getper(*it*100,CD)){
        ansAB=*it;
        ansCD=CD;
        per=getper(*it*100,CD);
      }
    }
  }
  cout<<ansAB*100+ansCD<<" "<<ansCD<<endl;
  return 0;
}
