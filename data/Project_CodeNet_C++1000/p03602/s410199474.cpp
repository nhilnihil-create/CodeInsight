#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX_V 333
#define INF 2000000001
int da[MAX_V][MAX_V];
int V; 
int ans=0;


void warshall_floyd(){
  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++){
	int tmp= da[i][j];
	da[i][j]=min(da[i][j],da[i][k]+da[k][j]);
	if(tmp!=da[i][j])ans=1;
      }
}

signed main(){
  cin>>V;

  for(int k=0;k<V;k++)
    for(int i=0;i<V;i++)
      cin>>da[k][i];
  
  warshall_floyd();
  if(ans)cout<<-1<<endl;
  else {
    int sum=0;
    for(int i=0;i<V;i++)
      for(int j=0;j<V;j++){
	int f=1;
	for(int k=0;k<V;k++){
	  if(k==i||k==j)continue;
	  if(da[i][k]+da[k][j]==da[i][j])f=0;
	}
	if(f)sum+=da[i][j];
      }
    cout<<sum/2<<endl;
  }
  return 0;
}
