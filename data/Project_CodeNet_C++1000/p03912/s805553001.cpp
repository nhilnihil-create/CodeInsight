#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int c[110000];
vector<int>g[110000];
int h[110000];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		scanf("%d",c+i);
		g[c[i]%b].push_back(c[i]);
		h[c[i]]++;
	}
	int ret=0;
	for(int i=0;i<b;i++){
		if((b-i)%b<i)continue;
		if((b-i)%b==i){
			ret+=g[i].size()/2;
		}else{
			int s=i;
			int t=(b-i)%b;
			if(g[s].size()<g[t].size()){
				swap(s,t);
			}
			ret+=g[t].size();
			int am=((int)g[s].size()-(int)g[t].size())/2;
			for(int j=s;j<=100000;j+=b){
				if(am==0)break;
				int can=min(h[j]/2,am);
				am-=can;
				ret+=can;
			}
		}
	}
	printf("%d\n",ret);
}