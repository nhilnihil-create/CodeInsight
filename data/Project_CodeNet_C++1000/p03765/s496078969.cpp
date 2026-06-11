#include<iostream>
using namespace std;
typedef long long ll;
signed main(){
  string s,t,ts,tt;
  ll sat,sbt,tat,tbt;
  ll q;
  cin >> s>>t>>q;
  ll query[4];
  ll ssum[s.size()][2];
  ll tsum[t.size()][2];
  fill(ssum[0],ssum[s.size()],0);
  fill(tsum[0],tsum[t.size()],0);

  for(int i=0;i<s.size();i++){
    if(s[i]=='A') ssum[i][0]++;
    else ssum[i][1]++;
    if(i!=0){
      ssum[i][0] += ssum[i-1][0];
      ssum[i][1] += ssum[i-1][1];
    }
  }
  for(int i=0;i<t.size();i++){
    if(t[i]=='A') tsum[i][0]++;
    else tsum[i][1]++;
    if(i!=0){
      tsum[i][0] += tsum[i-1][0];
      tsum[i][1] += tsum[i-1][1];
    }
  }
  for(int i=0;i<q;i++){
    for(int j=0;j<4;j++){
      cin >> query[j];
      query[j]--;
    }
    sat = ssum[query[1]][0];
    sbt = ssum[query[1]][1];

    tat = tsum[query[3]][0];
    tbt = tsum[query[3]][1];
    if(query[0]!=0){
      sat -= ssum[query[0]-1][0];
      sbt -= ssum[query[0]-1][1];
    }
    if(query[2]!=0){
      tat -= tsum[query[2]-1][0];
      tbt -= tsum[query[2]-1][1];
    }
    sbt += sat*2;
    tbt += tat*2; 
    if(sbt%3==tbt%3){
      cout <<"YES\n";
    }else{
      cout <<"NO\n";
    }
  }
}
