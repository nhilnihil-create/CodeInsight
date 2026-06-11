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
	int n;
	long long int k;
	long long int a[5000];
	scanf("%d %lld", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a+n);
	int i1=0, i2=n;
	while(i1!=i2){
		int imid=(i1+i2)/2;
		int s[5001]={};
		s[0]=1;
		for(int i=0; i<n; i++){
			if(i==imid) continue;
			for(int j=k-1;j>=0; j--){
				if(s[j]!=0 && j+a[i]<k) s[j+a[i]]++;
			}
		}
		int e=0;
		int j0=k-a[imid];
		if(k-a[imid]<=0) j0=0;
		for(int j=j0; j<k; j++){
			if(s[j]>0){
				e=1;
				break;
			}
		}
		if(e==1){
			i2=imid;
		}else{
			i1=imid+1;
		}
	}
	printf("%d\n", i1);
	return 0;
}