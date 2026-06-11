#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int dis[303][303];
bool notneed[303][303];
int main(){
  	int n;
	cin>>n;
  	for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
    		cin>>dis[i][j];
    	}
  	}
  	bool flag=true;
  	for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
      		for(int k=1;k<=n;++k){
    			if(i!=j&&j!=k&&k!=i){
      				if(dis[i][j]+dis[j][k]<dis[i][k])flag=false;
      				if(dis[i][j]+dis[j][k]==dis[i][k])notneed[i][k]=true;
    			}
      		}
    	}
  	}
  	if(!flag){
    	printf("-1\n");
  	}else{
    	long long ans=0;
    	for(int i=1;i<=n;++i){
      		for(int j=i+1;j<=n;++j){
    			if(!notneed[i][j])ans+=dis[i][j];
      		}
    	}
    	printf("%lld\n",ans);
  	}
  	return 0;
}