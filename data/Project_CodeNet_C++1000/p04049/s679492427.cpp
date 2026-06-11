#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin>>N>>K;
  int ans=INT_MAX;
  vector<vector<int>> A(N);
  vector<vector<int>> dist(N,vector<int>(N,-1));
  for(int i=0;i<N;i++){
    int a,b;cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  for(int s=0;s<N;s++){  //sは開始ポイント
    queue<int> q;
    q.push(s);dist[s][s]=0;
    while(q.size()){
      int attend=q.front();q.pop();  //aは今見つめているやつ
      for(int next:A[attend]){
        if(dist[s][next]==-1){
          q.push(next);
          dist[s][next]=dist[s][attend]+1;
        }
      }     
    }
  }
  
  if(K%2==0){
    for(int i=0;i<N;i++){
      int tmp=0;
      for(int j=0;j<N;j++){
        if(dist[i][j]>K/2)tmp++;
      }
      if(tmp<ans)ans=tmp;
    }
  }
  else{
    for(int c1=0;c1<N;c1++){
      for(int c2:A[c1]){
        int tmp=0;
        for(int i=0;i<N;i++){
          if(min(dist[i][c1],dist[i][c2])>K/2)tmp++;
        }
        if(tmp<ans)ans=tmp;
      }
    } 
  }
  cout<<ans;
}