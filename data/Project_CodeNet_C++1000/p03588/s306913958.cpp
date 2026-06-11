#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18

priority_queue<int,vector<int>,greater<int>> que;

void solve(){
	int n;
	cin >> n;
	int m=0;
	int ans;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(m<a){
			m=a;
			ans=a+b;
		}
	}
	cout << ans << endl;
}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
