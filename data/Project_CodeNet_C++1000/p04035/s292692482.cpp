#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 1e5 + 500;

int n, l, bst, a[N];

int main(){
	scanf("%d%d", &n, &l);
	for(int i = 0;i < n;i++){
		scanf("%d", a + i);
		if(i && a[i] + a[i - 1] >= l)
			bst = i;
	}
	if(!bst){
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	for(int i = 1;i < bst;i++)
		printf("%d\n", i);
	for(int i = n - 1;i > bst;i--)
		printf("%d\n", i);
	printf("%d\n", bst);
	
}	