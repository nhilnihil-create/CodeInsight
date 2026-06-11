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
	int h, H, w, W;
	scanf("%d %d %d %d", &H, &W, &h, &w);
	if(W%w!=0){
		printf("%s\n", "Yes");
		int x=W/w+1;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				if(j%w!=0){
					printf("%d ", x);
				}else{
					printf("%d ", -x*(w-1)-1);
				}
			}
			printf("\n");
		}
	}else if(H%h!=0){
		printf("%s\n", "Yes");
		int x=H/h+1;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				if(i%h!=0){
					printf("%d ", x);
				}else{
					printf("%d ", -x*(h-1)-1);
				}
			}
			printf("\n");
		}
	}else{
		printf("%s\n", "No");
	}
	return 0;
}