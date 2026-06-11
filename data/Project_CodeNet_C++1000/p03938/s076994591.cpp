#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

#define ll long long

#define debug_message 0
#define debug if (debug_message)

#define sz(x) (int)x.size()

int i,t,j;
int n,m,nt,p[20005],a[20005],b[20005],sum;
int adda,addb;
string s,s1,s2;
bool ok;

mt19937 gen(time(NULL));
uniform_int_distribution<int> dis(0,2e9);

int int_rd(int l, int r) {
	return dis(gen)%(r-l+1)+l;
}

int main() {
	scanf("%d",&n);

	for (i=1; i<=n; ++i) {
		scanf("%d",&p[i]);
	}

//	while(ok==0) {
//		for (i=1; i<=n; ++i) {
//			a[i]=int_rd(a[i-1]+1,a[i-1]+20005);
//		}
//		
//		for (i=n; i>=1; --i) {
//			b[i]=int_rd(b[i+1]+1,b[i+1]+20005);
//		}
//		
//		ok=1;
//		for (i=1; i<=n; ++i) {
//			if (a[p[i]]+b[p[i]]<=a[p[i-1]]+b[p[i-1]]) {
//				ok=0;
//				break;
//			}
//		}
//	}
	
	for (i=1; i<=n; ++i) a[i]=i*20005;
	for (i=n; i>=1; --i) b[i]=(n-i+1)*20005;
	
	for (i=1; i<=n; ++i){
		b[p[i]]-=10000-i;
	}

	for (i=1; i<=n; ++i) printf("%d%c",a[i],i==n?'\n':' ');
	for (i=1; i<=n; ++i) printf("%d%c",b[i],i==n?'\n':' ');

	return 0;
}
/*

*/