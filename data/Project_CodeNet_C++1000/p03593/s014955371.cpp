#include<bits/stdc++.h>
using namespace std;
const int maxn=550;
char ditu[maxn][maxn];
int cnt[maxn];
int n,m,t;
int sum1,sum2,sum3;
int main(){
//	scanf("%d",&t);
//	while(t--){
		memset(cnt,0,sizeof(cnt));
		memset(ditu,0,sizeof(ditu));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ditu[i][j];
				cnt[ditu[i][j]-'a'+1]++;
			}
		}
		sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=26;i++){
			while(cnt[i]>=4){
				cnt[i]-=4;
				sum1++;
			}
			if(cnt[i]>=2){
				cnt[i]-=2;
				sum2++;
			}
			if(cnt[i]) sum3++;
		}
		if(sum3>1||sum3==1&&!(n&1)||sum3==1&&!(m&1)){
			printf("No\n");
			return 0;
		}  
		if(sum1<(n/2)*(m/2)){
			printf("No\n");
			return 0;
		}
		printf("Yes\n");
//	}
	return 0;
}