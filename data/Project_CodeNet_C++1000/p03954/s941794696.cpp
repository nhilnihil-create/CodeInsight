#include<bits/stdc++.h>
using namespace std;
int len;
int n;
int a[1010100];
int b[1010100];

bool check(int x){
    for (int i=1;i<=n;i++) b[i] = a[i]>=x;
    int Mid = (1+n)>>1;
    int le=Mid-1,ri=Mid+1;
    for (;le && ri<=n;le--,ri++)
      if (b[le] == b[le+1]) return b[le];
      else if (b[ri] == b[ri-1]) return b[ri];
    return b[1];
}

int main(){
    scanf("%d",&len);
    n = 2*len-1;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l = 0,r = 1e9;
    while (l+1<r){
	    int mid = l+r>>1;
	    if (check(mid)) l = mid;else r = mid;
	}
	printf("%d",check(l)?l:r);
	return 0;
}