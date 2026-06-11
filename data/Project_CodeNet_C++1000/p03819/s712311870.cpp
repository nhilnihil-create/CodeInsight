#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,m,c[100050];
int main() {
	scanf("%d%d",&n,&m);
	int i,l,r;
	while(n--) {
		scanf("%d%d",&l,&r);l--;
		int lim=l,lst=0;
		for(i=1;i<=lim;i=lst+1) {
			lst=min(l/(l/i),r/(r/i));
			if(r/i-1>=l/i)c[i]++,c[lst+1]--;
		}
		c[lst+1]++,c[r+1]--;
	}for(i=1;i<=m;i++)c[i]+=c[i-1],printf("%d\n",c[i]);
}
