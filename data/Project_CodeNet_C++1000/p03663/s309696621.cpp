#include<bits/stdc++.h>
typedef long long ll;
bool check(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	char buf[10];
	scanf("%s",buf);
	return buf[0]=='Y';
}

void fin(ll x){
	printf("! %lld\n",x);
	fflush(stdout);
	exit(0);
}

int main()
{
	ll s=1e11,e=1e12,m;
	while(s<=e){
		m=(s+e)/2;
		if(check(m))e=m-1;
		else s=m+1;
	}
	while(s%10==0){
		if(!check(s+1))fin(s*10);
		s/=10;
	}
	if(s%10==9&&check(s*10-1)||s%10!=9&&!check(s+1))fin(s*10);
	else fin(s);
}
