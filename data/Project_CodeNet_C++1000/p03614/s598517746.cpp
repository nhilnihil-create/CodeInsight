#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int ret, cnt, n;

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x; scanf("%d",&x);
		if(x == i){
			cnt++;
		}
		else{
			ret += (cnt + 1) / 2;
			cnt = 0;
		}
	}
	ret += (cnt + 1) / 2;
	cout << ret << endl;
}
