//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200005;
const int MOD =1000000007;

signed main(){
  int n;
  cin>>n;
  int a,b;
  vector<int> hen[n];
  for(int i=0;i<n-1;i++){
    cin>>a>>b;
    a--;b--;
    hen[a].push_back(b);
    hen[b].push_back(a);
  }
  int iro[n]={},ans=0;
  queue<int> que[2][2];
  que[0][0].push(0);
  iro[0]=1;
  que[1][0].push(n-1);
  iro[n-1]=-1;
  while(!que[0][0].empty()||!que[1][0].empty()){
    while(!que[0][0].empty()){
      for(auto&& i: hen[que[0][0].front()])if(iro[i]==0){
        iro[i]=1;
        ans++;
        que[0][1].push(i);
        
      }
      que[0][0].pop();
    }
     swap(que[0][0],que[0][1]);
   while(!que[1][0].empty()){
      for(auto&& i: hen[que[1][0].front()])if(iro[i]==0){
        iro[i]=1;
        ans--;
        que[1][1].push(i);
        
      }
      que[1][0].pop();
    }
     swap(que[1][0],que[1][1]);
  
  }
  if(ans>0)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;

}