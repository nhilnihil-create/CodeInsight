#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int dx[]={-2,-2,-2,-1,-1,-1,0,0,0};
int dy[]={-2,-1,0,-2,-1,0,-2,-1,0};
pair<int,int> f[1100000];
long long ret[10];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int sz=0;
	for(int i=0;i<c;i++){
		int p,q;scanf("%d%d",&p,&q);
		p--;q--;
		for(int j=0;j<9;j++){
			int tx=p+dx[j];
			int ty=q+dy[j];
			if(tx>=0&&ty>=0&&tx<a-2&&ty<b-2){
				f[sz++]=make_pair(tx,ty);
			}
		}
	}
	std::sort(f,f+sz);
	int cnt=0;
	for(int i=0;i<sz;i++){
		if(i&&(f[i].first!=f[i-1].first||f[i].second!=f[i-1].second)){
			ret[cnt]++;
			cnt=1;
		}else{
			cnt++;
		}
	}
	if(sz)ret[cnt]++;
	long long cur=0;
	for(int i=0;i<10;i++)cur+=ret[i];
	ret[0]=(long long)(a-2)*(b-2)-cur;
	for(int i=0;i<10;i++)printf("%lld\n",ret[i]);
}