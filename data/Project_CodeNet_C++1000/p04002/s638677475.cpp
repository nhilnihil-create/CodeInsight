#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int dx[]={-2,-2,-2,-1,-1,-1, 0, 0,0};
const int dy[]={-2,-1, 0,-2,-1, 0,-2,-1,0};
long long Ans[10+2];
int N,M,K;
map<pair<int,int>,long long> P;
int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d %d %d",&N,&M,&K);
	Ans[0]=1LL*(N-2)*(M-2);
	for(int i=1;i<=K;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		for(int j=0;j<9;j++) {
			int tx=x+dx[j],ty=y+dy[j];
			if(tx<1||tx>N-2||ty<1||ty>M-2)
				continue;
			P[make_pair(tx,ty)]++;
		}
	}
	for(map<pair<int,int>,long long>::iterator it=P.begin();it!=P.end();it++) {
		Ans[0]--;
		Ans[it->second]++;
	}
	for(int i=0;i<10;i++)
		printf("%lld\n",Ans[i]);
	return 0;
}