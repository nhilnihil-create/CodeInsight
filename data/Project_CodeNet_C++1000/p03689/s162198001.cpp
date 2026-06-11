#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int H,W,h,w;
int ans[601][601];

int main(void){
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H%h==0 && W%w==0){
		puts("No");
		return 0;
	}
	if(W%w!=0){
		int c=W/w+1;
		int r=W-c;
		ll b=50000;
		ll a=b*(w-1)-1;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(j%w==0)ans[i][j]=a;
				else ans[i][j]=-b;
			}
		}
	}else{
		int c=H/h+1;
		int r=H-c;
		ll b=50000;
		ll a=b*(h-1)-1;
		for(int i=0;i<W;i++){
			for(int j=0;j<H;j++){
				if(j%h==0)ans[j][i]=a;
				else ans[j][i]=-b;
			}
		}
	}
	puts("Yes");
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			printf("%d%c",ans[i][j],j+1==W?'\n':' ');
		}
	}
	return 0;
}