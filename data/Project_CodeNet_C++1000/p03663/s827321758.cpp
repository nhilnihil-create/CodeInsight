#include<stdio.h>
bool query(long long int x){
	char s[9];
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s",s);
	return *s == 'Y';
}
void output(int x){
	printf("! %d\n",x);
	fflush(stdout);
}
int main(){
	int L = 1;
	long long int now = 1;
	for(; L <= 10; L ++){
		if(!query(now * 10))
			break;
		now *= 10;
	}
	if(L == 11){
		now = 1;
		while(!query(now * 10 - 1))
			now = now * 10;
		output((int)now);
		return 0;
	}
	int res = 0;
	for(int i=L; i>1; i--){
		int lo = 0, hi = 9;
		while(lo != hi){
			int mi = (lo + hi + 1)/2;
			bool flag = query(res * 10 + mi);
			if(flag)
				lo = mi;
			else
				hi = mi-1;
		}
		res = res * 10 + lo;
	}

	for(int i=(L==1?1:0); i<10; i++)
		if(query(res * 100LL + i * 10)){
			output(res * 10 + i);
			return 0;
		}
	return 0;
}