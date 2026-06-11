#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+10;

int p[MAXN];
int tmp[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &p[i]);
		tmp[i] = p[i];
	}

	int cnt1=0;
	for(int i=1;i<=n;i++) {
		if(i<n) {
			if(tmp[i]==i) {
				cnt1++;
				swap(tmp[i], tmp[i+1]);
			}	
		}
		else {
			if(tmp[i]==i) {
				cnt1++;
					
			}
			
		}
	}

	int cnt2=0;
	for(int i=1;i<=n;i++)
		tmp[i] = p[i];

	for(int i=n;i>=1;i--) {
		if(i>=2) {
			if(tmp[i]==i) {
				cnt2++;
				swap(tmp[i], tmp[i-1]);
			}	
		}
		else {
			if(tmp[i]==i) {
				cnt2++;
				swap(tmp[i], tmp[i+1]);	
			}
		}
	}
	// printf("%d %d\n", cnt1, cnt2);
	printf("%d", min(cnt1, cnt2));
	return 0;
}