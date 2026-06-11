#include<cstdio>
#include<algorithm>
using namespace std;
int a,cnt[105],n,l;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		l=max(l,a);
		cnt[a]++;
	}
	if(l&1){
		for(int i=0;i<=l/2;i++)
			if(cnt[i])return printf("Impossible"),0;
		if(cnt[l/2+1]!=2)return printf("Impossible"),0;
		for(int i=l/2+2;i<=l;i++)
			if(cnt[i]<2)return printf("Impossible"),0;
	}
	else{
		for(int i=0;i<l/2;i++)
			if(cnt[i])return printf("Impossible"),0;
		if(cnt[l/2]!=1)return printf("Impossible"),0;
		for(int i=l/2+1;i<=l;i++)
			if(cnt[i]<2)return printf("Impossible"),0;
	}
	printf("Possible");
	return 0;
}