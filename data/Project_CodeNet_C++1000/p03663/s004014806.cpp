#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define rep2(i,k,n) for(int i=k;i>=n;i--)
using namespace std;
int a[10],l[10],r[10],cnter=0,lt,rt;
char s[10];
int cal(long long x){
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y' ? 1 : 0;
}
void solve(int op){
	int L=l[op],R=r[op];
	while(L<R){
		int mid=(L+R)>>1;
		if(cal(10ll*mid))R=mid;
		else L=mid+1; 
	}
	printf("! %d\n",L);
}
int main(){
	l[1]=1,r[1]=9;
	rep(i,2,9){
		l[i]=l[i-1]*10;
		r[i]=r[i-1]*10+9;
	}
	rep(i,1,9)a[i]=cal(l[i]) && cal(r[i]),cnter+=a[i];
	rep(i,1,9)if(a[i])rt=i;
	rep2(i,9,1)if(a[i])lt=i;
	
	if(!cnter){
		printf("! 1000000000\n");
		//fflush(stdout);
	}else if(cnter==9){
		int pan=cal(1000000000ll);
		if(pan)printf("! %d\n",l[1]);
		else solve(rt);
	}
	else if(a[9] && a[1]){
		solve(rt);
	}
	else if(!a[9]){
		solve(rt);
	}else if(!a[1]){
		solve(lt);
	}
}