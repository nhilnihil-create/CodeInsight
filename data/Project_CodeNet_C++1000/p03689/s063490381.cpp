#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define ty 2443
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);
}
int co[510][510];

int main(){
	int H,W,h,w;read(H);read(W);read(h);read(w);
	if(H%h==0&&W%w==0){puts("No");return 0;}
	
	puts("Yes");
	if(H%h!=0){
		rep(i,1,H){
			rep(j,1,W){
				if((i-1)%h!=0){co[i][j]=-ty;}
				else{co[i][j]=ty*(h-1)-1;}
			}
		}
	}else{
		rep(i,1,H){
			rep(j,1,W){
				if((j-1)%w!=0){co[i][j]=-ty;}
				else{co[i][j]=ty*(w-1)-1;}
			}
		}
	}
	
	rep(i,1,H){
		rep(j,1,W){write(co[i][j]);putchar((j==W)?'\n':' ');}
	}
	return 0;
}
