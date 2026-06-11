#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int main(){
  int n;
  cin>>n;
  vector<int> G[100001];
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int used[100001]={};
  int cntf=0,cnts=0;
  queue<P> fq,sq;
  fq.push(P(1,0));
  sq.push(P(n,0));
  int t=0;
  while(!fq.empty()||!sq.empty()){
    while(!fq.empty()&&fq.front().second==t){
      int to=fq.front().first;
      fq.pop();
      if(!used[to]){
	//cout<<to<<endl;
	for(int i=0;i<G[to].size();i++)fq.push(P(G[to][i],t+1));
	used[to]=1;
	cntf++;
      }
    }
    while(!sq.empty()&&sq.front().second==t){
      int to=sq.front().first;
      sq.pop();
      if(!used[to]){
	//cout<<to<<endl;
	for(int i=0;i<G[to].size();i++)sq.push(P(G[to][i],t+1));
	used[to]=1;
	cnts++;
      }
    }
    t++;
  }
  if(cntf>cnts)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
}
