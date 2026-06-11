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
		int l=X,r=X*10-1;
		for (;l<=r;){
			int mid=(l+r)>>1;
			if (query(mid*10ll)) X=mid,r=mid-1;
				else l=mid+1;
		}
	}
	printf("! %lld\n",X);
	fflush(stdout);
	return 0;
}