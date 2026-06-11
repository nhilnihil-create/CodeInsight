#include<stdio.h>
#include <cstring>
typedef long long LL;

LL ans,a;
bool Query(LL q){
	printf("? %lld\n",q);
	fflush(stdout);


	char str[10];
	scanf("%s",str);
	if(str[0]=='Y') return true;
	else return false;
}
LL query(LL x,int t){
	LL y=x;
	for(int i=1;i<=t;++i) y=y*10+9;
	return y;
}
void GetFirst(){
	int l=1,r=9,mid;
	while(l<=r){
		mid=((l+r)>>1);
		LL q=query((LL)mid,10);
		if(Query(q)) r=mid-1;
		else l=mid+1;
	}
	a=r+1;
}


int GetNewbit(int len){
	int l=0,r=9,mid;


	while(l<=r){
		mid=((l+r)>>1);
		LL q=query(a*10+mid,len);
		if(Query(q)) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}		
void JUDGE(){
	GetFirst();
	int len=9;
	while(1){
		int x=GetNewbit(len); --len;
		a=a*10LL+x;
		if(x==0){
			int cnt=0;
			for(LL y=a;y;y/=10) cnt+=y%10;
			LL y=a-1;
			if(cnt==1){
				if(Query(y)){
					ans=a/10;
					return;
				}
			}
			else{
				if(!Query(y)){
					ans=a/10;
					return;
				}
			}
		}
	}
}


int main(){
	JUDGE();
	printf("! %lld\n",ans);
	fflush(stdout);
}
			
			
