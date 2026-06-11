#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

int N,M;
int X[100000];

int Y[100001];
vector< P > G[100001];

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&X[i]);
    Y[ X[i] ]++;
  }
  for(int i=1;i<=100000;i++){
    if(Y[i]==0)continue;
    int num=Y[i];
    if(num-num%2>0)
      G[ i%M ].push_back( P( num - num%2 , i ) );
    
    if( num%2 > 0 )
      G[ i%M ].push_back( P( num%2 , i ) );
  }

  for(int i=0;i<M;i++){
    sort(G[i].begin(),G[i].end());
    reverse(G[i].begin(),G[i].end());
  }

  int ans=0;
  for(int i=1;i<M;i++){
    int pos=i;
    int target=M-i;
    if( target < pos )break;
    
    while(1){
      if(G[target].empty() || G[pos].empty())break;

      ans++;
      
      P pa=G[target].back();
      G[target].pop_back();
      pa.first--;
      if(pa.first>0)G[target].push_back(pa);

      if(G[pos].empty()){
        pa.first++;
        G[pos].push_back(pa);
        ans--;
        break;
      }

      P pb=G[pos].back();
      G[pos].pop_back();
      pb.first--;
      if(pb.first>0)G[pos].push_back(pb);      

    }
  }
  
  int zcnt=0;
  for(int i=1;i<M;i++){
    map<int,int> mp;
    for(int j=0;j<(int)G[i].size();j++){
      P p=G[i][j];
      mp[ p.second ] += p.first;
    }

    for( P p : mp ){

      int k=p.second/2;
      ans+=k;

      //      while(k--){ cout<<p.first<<' '<<p.first<<endl; }
      
    }
  }
  
  for(int i=0;i<(int)G[0].size();i++)
    zcnt+=G[0][i].first;
  

  int tmp =zcnt/2;
  ans+=tmp;

  //  cout<<zcnt<<endl;
  
  cout<<ans<<endl;
  return 0;
}
