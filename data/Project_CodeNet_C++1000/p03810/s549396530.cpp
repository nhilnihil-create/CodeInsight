#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

const int N=1e5+5;

ll sum;
int a[N],n;

int gcd(int x,int y) {return y?gcd(y,x%y):x;}

bool dfs() {
	sum=0;
	fo(i,1,n) sum+=a[i];
	if (!(sum&1)) {
		if (n&1) return 1;
		else return 0;
	}
	if (!(n&1)) return 1;
	int cnt=0,id=0;
	fo(i,1,n) if ((a[i]&1)&&a[i]!=1) cnt++,id=i;
	if (cnt!=1) return 0;
	a[id]--;int g=a[1];
	fo(i,2,n) g=gcd(g,a[i]);
	fo(i,1,n) a[i]/=g;
	return dfs()^1;
}

int main() {
	scanf("%d",&n);
	fo(i,1,n) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if (!(sum&1)) {
		if (n&1) puts("First");
		else puts("Second");
		return 0; 
	}
	if (!(n&1)) {puts("First");return 0;}
	bool ok=dfs();
	if (ok) puts("First");
	else puts("Second");
	return 0;
}