#include <cstdio>

bool query(long long x){
	printf("? %lld\n",x);
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	return s[0]=='Y';
}

int main(){
	long long X=1000000000;
	for (;!query(X);X/=10);
	if (X==1000000000)
		for (X=1;!query(X+1);X*=10);
	else{
		int l=X/10,r=X-1;
		if (!r) X=10;
		else
		for (;l<=r;){
			int mid=(l+r)>>1;
			if (query(mid)) X=mid*100ll,l=mid+1;
				else r=mid-1;
		}
		for (;!query(X);X+=10);
		X/=10;
	}
	printf("! %lld\n",X);
	fflush(stdout);
	return 0;
}