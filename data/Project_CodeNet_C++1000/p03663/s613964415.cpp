#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int l=1,r=1e9,mid;
char s[5];

char Query(ll x){printf("? %lld\n",x);fflush(stdout);scanf("%s",s);return*s;}
void Answer(int x){printf("! %d\n",x);exit(0);}

void powten(){
	int t=1;
	while(true){
		if(Query(t+1)=='Y')Answer(t);
		t*=10;
	}
	exit(0);
}

int main(){
	do{
		if(l==r)powten();
	}while(Query(l*=10)=='Y');
	r=min(r,l-1),l/=10,mid=(l+r)>>1;
	while(l<r){
		if(Query(mid*10ll+9)=='Y')
			r=mid;
		else
			l=mid+1;
		mid=(l+r)>>1;
	}
	Answer(mid);
	return 0;
}