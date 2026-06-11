#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;


signed main(){
  string s,t,u;
  cin>>s;
  REP(i,s.size())t+=s[s.size()-1-i];
  REP(i,t.size()){
    if(t[i]=='b')u+="d";
    else if(t[i]=='d')u+="b";
    else if(t[i]=='p')u+="q";
    else u+="p";
  }
  if(s==u)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
