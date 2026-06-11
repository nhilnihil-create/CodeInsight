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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

db x[N],tmp;
int P[60][N],Q[N];
int A[N];
int n,m,u;
ll K;

int main(){
	n=IN();
	For(i,1,n+1) x[i]=IN();
	m=IN(),K=IN();
	For(i,1,n){
		P[0][i]=i;
		Q[i]=i;
	}
	For(i,1,m+1){
		u=IN();
		swap(P[0][u],P[0][u-1]);
	}
	For(t,1,60){
		For(i,1,n) P[t][i]=P[t-1][P[t-1][i]];
	}
	For(t,0,60) if (K>>t&1){
		For(i,1,n) Q[i]=P[t][Q[i]];
	}
	tmp=x[1];
	printf("%.10lf\n",tmp);
	For(i,1,n){
		tmp+=x[Q[i]+1]-x[Q[i]];
		printf("%.10lf\n",tmp);
	}
}