#include<bits/stdc++.h>
typedef long long i64;
i64 pw10[20];
//i64 _ans;
//char _s1[20],_s2[20];
bool Q(i64 x){
	printf("? %lld\n",x),fflush(stdout);
//	memset(_s1,0,sizeof(_s1));
//	memset(_s2,0,sizeof(_s2));
//	sprintf(_s1,"%lld",x);
//	sprintf(_s2,"%lld",_ans);
//	bool d=(x<=_ans)==(strcmp(_s1,_s2)<=0);
//	puts(d?"Y":"N");
//	return d;
	char c;
	scanf(" %c",&c);
	return c=='Y';
}
void A(i64 x){
	printf("! %lld\n",x),fflush(stdout);
}
int main(){
//	scanf("%lld",&_ans);
	pw10[0]=1;
	for(int i=1;i<=12;++i)pw10[i]=pw10[i-1]*10ll;
	if(Q(pw10[12])){
		int p=9;
		while(p&&Q(pw10[p]-1))--p;
		A(pw10[p]);
	}else{
		int p=0;
		while(Q(pw10[p]))++p;
		i64 L=pw10[p],R=L*10-1,M;
		while(L<R){
			M=L+R>>1;
			if(Q(M))R=M;
			else L=M+1;
		}
		A(L/10);
	}
	return 0;
}