#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;

bool ok(int x){
    int m = n - x;
    LL sum = 1LL * x * (x - 1) / 2;
    if(sum < m)	return 0;
    return 1;
}

int main(){
	while(~scanf("%d", &n)){
		int low = 1, top = n, ans = n, mid;
		while(low <= top){
			mid = low + top >> 1;
			if(ok(mid)){
                ans = min(ans, mid);
                top = mid - 1;
			} else {
				low = mid + 1;
			}
		}
        for(int i=ans; i>=1; i--){
            if(n <= i){
                printf("%d\n", n);
                for(int j=i+1; j<=ans; j++){
					printf("%d\n", j);
                }
                break;
            } else {
				n -= i;
            }
        }
	}
	return 0;
}
