#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=(y);x<(z);x++)
#define F2(x,y,z) for(int x=(y);x<=(z);x++)
#define F3(x,y,z) for(int x=(y);x>(z);x--)
#define F4(x,y,z) for(int x=(y);x>=(z);x--)
#define mp make_pair
#define pb push_back
#define LL long long
#define co complex<double>
#define fi first
#define se second

#define MAX 100005
#define AMAX 1025*1005
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int n,x[MAX],y[2],g;
bool f,m,o;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int main(){
	scanf("%d",&n);
	F1(a,0,n)scanf("%d",x+a);
	while(1){
		y[0]=y[1]=0;
		m=1-m;
		F1(a,0,n)y[x[a]&1]++;
		if(y[0]&1){
			f=m;
			break;
		}else if(y[1]>1){
			f=1-m;
			break;
		}else{
			F1(a,0,n)if(x[a]&1){
				if(x[a]==1)f=1-m,o=1;
				x[a]--;
				break;
			}
			if(o)break;
			g=x[0];
			F1(a,1,n)g=gcd(g,x[a]);
			F1(a,0,n)x[a]/=g;
		}
	}
	if(f)printf("First\n");
	else printf("Second\n");
	#ifdef LOCAL_PROJECT
	system("pause");
	#endif
	return 0;
}
