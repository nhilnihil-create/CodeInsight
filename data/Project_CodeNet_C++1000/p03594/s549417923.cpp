#include<bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_H=500,MAX_W=500;
int H,W,d;
char col[4]={'R','Y','G','B'};
char ans[MAX_H][MAX_W+1];
void pnt(int h,int w,int c){
	for(int i=h;i<h+d;i++){
		for(int j=w-d/2;j<=w+d/2;j++){
			if(i<0 || i>=H || j<0 || j>=W)continue;
			if(abs(h-i)+abs(w-d/2-j)<d/2 ||
			abs(h+d-1-i)+abs(w+d/2-j)<d/2){
				ans[i][j]=col[(c==0 ? 2 : 3)];
			}else if(abs(h-i)+abs(w+d/2-j)<d/2 ||
			abs(h+d-1-i)+abs(w-d/2-j)<d/2){
				ans[i][j]=col[(c==0 ? 3 : 2)];
			}else{
				ans[i][j]=col[c];
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&H,&W,&d);
	if(d%2){
		REP(h,H){
			REP(w,W){
				ans[h][w]=col[h%2*2+w%2];
			}
		}
	}else{
		for(int h=0;h<H;h+=d){
			int f=h/d%2;
			for(int w=d/2-1;w<W+d/2;w+=d){
//				printf("pnt %d %d %d\n",h,w,f);
				pnt(h,w,f);
				f=1-f;
			}
		}
	}
	REP(h,H){
		printf("%s\n",ans[h]);
	}
}