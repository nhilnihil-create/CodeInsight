#include <map>
#include <cstdio>
using namespace std;
map <int ,map <int ,int > > ma;
long long ans[12];
int dx[12]={0,0,1,0,-1,1,1,-1,-1},
	dy[12]={0,1,0,-1,0,1,-1,1,-1};
int main (){
	int n,m,k;scanf ("%d%d%d",&n,&m,&k);
	ans[0]=1ll*(n-2)*(m-2);
	while (k--){
		int x,y;scanf ("%d%d",&x,&y);
		for (int i=0;i<=8;i++){
			int tx=x+dx[i],ty=y+dy[i];
			if (tx<n&&ty<m&&tx>1&&ty>1){
				ans[ma[tx][ty]]--,ans[++ma[tx][ty]]++;
			}
		}
	}
	for (int i=0;i<=9;i++) printf ("%lld\n",ans[i]);
	return 0;
}
