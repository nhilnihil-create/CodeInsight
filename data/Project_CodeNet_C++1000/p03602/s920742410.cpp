# include "iostream"
# include "cstdio"

using namespace std;

const int maxm=3e2+10;

int N;
long long Map[maxm][maxm];
bool Visit[maxm][maxm];

int main(){
	register int i,j,k;
	long long Ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf("%lld",&Map[i][j]);
			Ans+=Map[i][j];
		}
	}
	for(k=1;k<=N;k++){
		for(i=1;i<=N;i++){
			if(i==k) continue;
			for(j=1;j<=N;j++){
				if(j==i || j==k) continue;
				if(Map[i][j]>Map[i][k]+Map[j][k]){
					printf("-1");
					return 0;
				}
				if(Visit[i][j]) continue;
				if(Map[i][j]==Map[i][k]+Map[k][j]){
                    Ans-=Map[i][j];
                    Visit[i][j]=1;
				}
			}
		}
	}
	Ans>>=1;
	cout<<Ans;
	return 0;
}