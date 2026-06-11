#include<bits/stdc++.h>

#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
const int MAX_V=310;
ll d[MAX_V][MAX_V];
ll V;
void warshall_floyd(){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++)
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
ll cnt=0;
bool flag=false;
void warshall_floyd2(){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=i+1;j<V;j++){
	if(d[i][j]!=llINF&&d[i][j] == d[i][k]+d[k][j]&&i<j&&i!=k&&j!=k){
	  //cout<<d[i][j]<<endl;
	  flag=true;
	  cnt+=d[i][j];
	  //cout<<d[i][j]<<endl;
	  d[i][j]=llINF;
	}
      }
	
}
int main(){
  cin>>V;
  ll ori[MAX_V][MAX_V]={}; 
  for(int i=0;i<V;i++)
    for(int j=0;j<V;j++){
      cin>>d[i][j];
      ori[i][j]=d[i][j];
    }
  warshall_floyd();
  bool flag=false;
  for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
      if(ori[i][j]!=d[i][j]){
	flag=true;
	break;
      }
    }
    if(flag)break;
  }
  if(flag){
    cout<<-1<<endl;
    return 0;
  }
  while(1){
    warshall_floyd2();
    if(!flag)break;
    flag=true;
  }
  ll ans=0;
  for(int i=0;i<V;i++){
    for(int j=i+1;j<V;j++){
      if(d[i][j]!=llINF)
	ans+=d[i][j];
    }
  }
  cout<<ans<<endl;
  return 0;
}
