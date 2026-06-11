#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long int x[100000];
	long long int d[100000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &x[i]);
		if(i>0){
			d[i-1]=x[i]-x[i-1];
		}
	}
	int m;
	long long int k;
	scanf("%d %lld", &m, &k);
	int ind[100000][60];
	int ind1[100000];
	for(int i=0; i<n-1; i++){
		ind[i][0]=i;
		ind1[i]=i;
	}
	int a;
	for(int i=0; i<m; i++){
		scanf("%d", &a);
		a--;
		int j;
		j=ind[a][0];
		ind[a][0]=ind[a-1][0];
		ind[a-1][0]=j;
	}
	int c[100000];
	for(int i=0; i<n-1; i++){
		c[ind[i][0]]=i;
	}
	for(int i=0; i<n-1; i++){
		ind[i][0]=c[i];
	}
	long long int p2[60];
	p2[0]=1;
	for(int i=1; i<60; i++){
		p2[i]=p2[i-1]*2;
	}
	for(int i=1; i<60; i++){
		for(int j=0; j<n-1; j++){
			ind[j][i]=ind[ind[j][i-1]][i-1];
		}
	}
	
	for(int i=59; i>=0; i--){
		if(k>=p2[i]){
			for(int j=0; j<n-1; j++){
				ind1[j]=ind[ind1[j]][i];
			}
		}
		k=k%p2[i];
	}
	for(int i=0; i<n-1; i++){
		c[ind1[i]]=i;
	}
	printf("%.1lf\n", (double)x[0]);
	for(int i=1; i<n; i++){
		x[i]=x[i-1]+d[c[i-1]];
		double x1=(double)x[i];
		printf("%.1lf\n", x1);
	}
	return 0;
}