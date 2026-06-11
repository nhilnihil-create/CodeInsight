#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

char s[5];

bool check(ll x){
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y';
}
void Work(ll l,ll r){
	ll res;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid*10)) res=mid,r=mid-1;else l=mid+1;
	}
	printf("! %lld\n",res);
	fflush(stdout);
	exit(0);
}

int main(){
	for (ll i=10;i<=ll(1e11);i*=10)
		if (!check(i)){
			Work(i/10,i-1);
		}
	for (ll i=9,j=1;;i=i*10+9,j*=10)
		if (check(i)){
			printf("! %lld\n",j);
			fflush(stdout);
			return 0;
		}
}