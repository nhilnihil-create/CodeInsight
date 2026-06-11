#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n;
int A[100010];
char op[100010];

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", A+i);
		if(i != n)scanf(" %c", op+i);
	}
	int pre = -1;
	ll mx = 0, mn = 0;
	for(int i=n-1;i;i--){
		if(op[i] == '-'){
			if(pre == -1){
				mx = -A[i+1];
				mn = -A[i+1];
				for(int j=i+2;j<=n;j++)mx += A[j], mn -= A[j];
			}
			else{
				ll sum = 0;
				for(int j=i+2;j<=pre;j++)sum += A[j];
				ll nmx = max(-A[i+1] + sum + mx, -A[i+1] - sum - mn);
				ll nmn = min(-A[i+1] - sum + mn, -A[i+1] - sum - mx);
				mx = nmx; mn = nmn;
			}
			pre = i;
		}
	}
	mx += A[1];
	for(int i=1;i<n;i++){
		if(op[i] == '-')break;
		mx += A[i+1];
	}
	printf("%lld\n", mx);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}