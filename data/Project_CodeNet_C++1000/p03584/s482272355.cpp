#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <map>
#include <set>
using namespace std;
const int INF = 1000000009;

unsigned long n, k;
unsigned long a[100000];
unsigned long b[100000];

/*void binlook(int i){
	stack<int> st;
	while(i){
		st.push(i%2);
		i /= 2;
	}
	while(!st.empty()){
		printf("%d", st.top());
		st.pop();
	}
	return;
}*/

int main(){
	scanf("%ld%ld", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%ld%ld", &a[i], &b[i]);
	}
	unsigned long ans = 0;
	for(unsigned long i = 1; i <= k; i <<= 1){
		if(!(i & k)){
			continue;
		}
		unsigned long vis = ((k & (~i)) | (i-1));
		unsigned long res = 0;
		for(unsigned long x = 0; x < n; x++){
			if(vis == (vis | a[x])){
				//printf("%d ", a[x]);
				res += b[x];
			}
			//printf("\n");
		}
		//printf("i = %d, vis = %d -> res %d\n", i, vis, res);
		if(res > ans){
			ans = res;
		}
	}
	unsigned long res = 0;
	for(unsigned long i = 0 ; i < n; i++){
		if((a[i] | k) == k){
			res += b[i];
		}
	}
	ans = max(res, ans);
	printf("%ld\n", ans);
	return 0;
}