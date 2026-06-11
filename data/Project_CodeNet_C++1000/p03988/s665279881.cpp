#include<cstdio>
using namespace std;
#define N 110
#define rep(i,j,k) for(i=j;i<=k;++i)
int n,i,j,k,sum;
int num[N];
void read(int &p){
	p=0; char x=getchar();
	while(x<'0' || x>'9') x=getchar();
	while(x>='0'&&x<='9'){p=p*10+x-'0'; x=getchar();}
}
int main(){
	read(n);
	rep(i,1,n){
		read(k);
		num[k]++;
		if(sum<k) sum=k;
	}
	i=sum;
	while(sum>1){
		if(num[i]<2) {
			puts("Impossible");
			return 0;
		}
		i--; sum-=2;
	}
	if(sum) {
		if(num[i]!=2) {
			puts("Impossible");
			return 0;
		}
	}else{
		if(num[i]!=1){
			puts("Impossible");
			return 0;
		}
	}
	rep(i,1,i-1)
	if(num[i]){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	return 0;
}