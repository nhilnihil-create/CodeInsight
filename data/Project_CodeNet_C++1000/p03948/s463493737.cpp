#include <cstdio>
#include <algorithm>
using namespace std;

int leftMin = 1e9+7;
int diff, ans;

int main(){
	int N, a;
	scanf("%d %d", &N, &a);
	while(N--){
		scanf("%d", &a);
		if(a - leftMin == diff){
			++ans;
		}
		else if(a - leftMin > diff){
			diff = a - leftMin;
			ans = 1;
		}
		leftMin = min(leftMin, a);
	}
	printf("%d\n", ans);
}
