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

void solve(){
	int N; scanf("%d", &N);
	for(int i=1;;i++){
		if((i+1) * i / 2 >= N){
			vector <int> ans;
			for(int j=i;j;j--){
				if(j*(j-1)/2 < N)ans.pb(j), N -= j;
			}
			reverse(all(ans));
			for(auto e : ans)printf("%d\n", e);
			return;
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}