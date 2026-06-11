#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n, w[100001];
	long long int l, t, x[100001], y[100001];
	scanf("%d %lld %lld", &n, &l, &t);
	l=l*2;
	t=t*2;
	vector<int> i1, i2;
	int e1=0, e2=0;
	for(int i=0; i<n; i++){
		scanf("%lld %d", &x[i], &w[i]);
		x[i]=x[i]*2;
		if(w[i]==1){
			y[i]=(x[i]+t)%l;
			i1.push_back(i);
			e1=1;
		}else{
          if(x[i]+l-t>=0){
			y[i]=(x[i]+l-t)%l;
          }else{
            y[i]=(l-(-(x[i]+l-t))%l)%l;
          }
			i2.push_back(i);
			e2=1;
		}
	}
	if(e1==0 || e2==0){
		for(int i=0; i<n; i++){
			printf("%lld\n", y[i]/2);
		}
	}else if(w[0]==1){
		long long int n2=i2.size();
		long long int t0[200002];
		for(int i=1; i<=n2; i++){
			t0[i]=(x[i2[i-1]]-x[0])/2;
		}
		for(int i=n2+1; i<=2*n2; i++){
			t0[i]=(x[i2[i-n2-1]]-x[0]+l)/2;
		}
		long long int tq=t/l, tr=t%l;
		long long int k;
		for(int i=1; i<2*n2; i++){
			if(t0[i]<=tr && tr<t0[i+1]) k=i;
		}
		if(tr<t0[1]) k=0;
		if(tr>=t0[2*n2]) k=2*n2;
		k=(tq*2*n2+k)%n;
		long long int ans[100000];
		long long int y0=y[0];
		ans[k]=y0/2;
		sort(y, y+n);
		int k1;
		for(int i=0; i<n; i++){
			if(y[i]==y0)  k1=i;
		}
		if(k1==n-1 && y[0]==y0) k1=0;
		for(int i=0; i<n; i++){
			int p=i+k, q=i+k1;
			if(p>=n) p=p-n;
			if(q>=n) q=q-n;
			ans[p]=y[q]/2;
		}
		for(int i=0; i<n; i++){
			printf("%lld\n", ans[i]);
		}
	}else{
		long long int n1=i1.size();
		long long int t0[200002];
		for(int i=1; i<=n1; i++){
			t0[i]=(l-x[i1[n1-i]]+x[0])/2;
		}
		for(int i=n1+1; i<=2*n1; i++){
			t0[i]=(l-x[i1[2*n1-i]]+x[0]+l)/2;
		}
		long long int tq=t/l, tr=t%l;
		long long int k;
		for(int i=1; i<2*n1; i++){
			if(t0[i]<=tr && tr<t0[i+1]) k=n-i;
		}
		if(tr<t0[1]) k=0;
		if(tr>=t0[2*n1]) k=n-2*n1;
		k=(n+k+2*(n-n1)*tq)%n;
		long long int ans[100000];
		long long int y0=y[0];
		ans[k]=y0/2;
		sort(y, y+n);
		int k1;
		for(int i=0; i<n; i++){
			if(y[i]==y0){
				k1=i;
				break;
			}
		}
		if(k1==0 && y[n-1]==y0) k1=n-1;
		for(int i=0; i<n; i++){
			int p=i+k, q=i+k1;
			if(p>=n) p=p-n;
			if(q>=n) q=q-n;
			ans[p]=y[q]/2;
		}
		for(int i=0; i<n; i++){
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}