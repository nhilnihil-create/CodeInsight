#include<bits/stdc++.h>
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
  int w,h;
  cin>>w>>h;
  vector<pair<int,int>> v;
  REP(i,w){
    int p;
    cin>>p;
    v.PB(MP(p,0));
  }
  REP(i,h){
    int q;
    cin>>q;
    v.PB(MP(q,1));
  }
  sort(ALL(v));
  int sum=0;
  int x=h+1;
  int y=w+1;
  REP(i,w+h){
    if(v[i].SEC==0){
      sum+=v[i].FIR*x;
      y--;
    }else{
      sum+=v[i].FIR*y;
      x--;
    }
  }
  cout<<sum<<endl;
  return 0;
}
