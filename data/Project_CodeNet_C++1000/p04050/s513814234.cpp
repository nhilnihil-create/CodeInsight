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

Vi V,odd,res;
int n,m,x;

int main(){
	n=IN(),m=IN();
	For(i,0,m){
		x=IN();
		if (x&1) odd.pb(x);else V.pb(x);
	}
	if (odd.size()>2){
		puts("Impossible");
		return 0;
	}
	if (odd.size()) res.pb(odd.back()),odd.pop_back();
	For(i,0,V.size()) res.pb(V[i]);
	if (odd.size()) res.pb(odd.back()),odd.pop_back();
	if (res.size()==1){
		printf("%d\n",res[0]);
		if (res[0]==1){
			printf("1\n");
			printf("1\n");
		} else{
			printf("2\n");
			printf("%d %d\n",res[0]-1,1);
		}
	} else{
		For(i,0,res.size()) printf("%d ",res[i]);
		puts("");
		res[0]++;
		res.back()--;
		if (res.back()==0) res.pop_back();
		printf("%d\n",res.size());
		For(i,0,res.size()) printf("%d ",res[i]);
		puts("");
	}
}