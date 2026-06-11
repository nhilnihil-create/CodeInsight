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
	int n, t, ans=0;
	long long int a[100000], amax[100000], max;
	scanf("%d %d", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%lld\n", &a[i]);
	}
	for(int i=n-1; i>=0; i--){
		if(i==n-1){
			amax[n-1]=a[n-1];
		}else{
			if(amax[i+1]<a[i]){
				amax[i]=a[i];
			}else{
				amax[i]=amax[i+1];
			}
		}
	}
	for(int i=0; i<n-1; i++){
		if(i==0){
			max=amax[1]-a[0];
			ans=1;
		}else if(max<amax[i+1]-a[i]){
			max=amax[i+1]-a[i];
			ans=1;
		}else if(max==amax[i+1]-a[i]){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}