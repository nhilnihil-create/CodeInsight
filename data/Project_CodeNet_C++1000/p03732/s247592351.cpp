#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;

vector<ll> V[4];
ll sum[4][110];

int main(){
  int N;
  ll W,w[110],v[110],ans=0,temp=0;
  
  cin>>N>>W;
  
  for(int i=0;i<N;i++){
    cin>>w[i]>>v[i];
    if(i==0) V[0].push_back(v[i]);
    else V[w[i]-w[0]].push_back(v[i]);
  }
  
  int n[4];
  for(int i=0;i<4;i++){
    V[i].push_back(10000000000);
    n[i]=(int)V[i].size();
  } 
  //cout<<n[1]<<endl;

  for(int i=0;i<4;i++){
    sort(V[i].begin(),V[i].end(),greater<ll>());
    V[i][0]=0;
  } 
  //cout<<V[2][1]<<endl;
  for(int i=0;i<4;i++){
    for(int j=0;j<n[i];j++){
      if(j==0) sum[i][j]=V[i][j];
      else sum[i][j]+=sum[i][j-1]+V[i][j];
    }
  }

  for(int i=0;i<n[0];i++){
    for(int j=0;j<n[1];j++){
      for(int k=0;k<n[2];k++,temp=0){
        //cout<<(i+j+k)*w[0]+j+k*2<<endl;
        if((i+j+k)*w[0]+j+k*2>W) break;
        temp=sum[0][i]+sum[1][j]+sum[2][k];
        if((W-(i+j+k)*w[0]-j-k*2)/(w[0]+3)>=n[3]) temp+=sum[3][n[3]-1];
        else temp+=sum[3][(W-(i+j+k)*w[0]-j-k*2)/(w[0]+3)];
        //cout<<i<<" "<<j<<" "<<k<<" "<<temp<<endl;
        ans=max(temp,ans);
      }
    }
  }
  cout<<ans<<endl;
}
