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
	int H, W; scanf("%d%d", &H, &W);
	rep(i, H)rep(j, W){
		string s; cin >> s;
		if(s == "snuke"){
			printf("%c%d", j+'A', i+1);
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