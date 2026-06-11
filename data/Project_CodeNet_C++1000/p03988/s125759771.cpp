#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

LL n,a;
LL mx = 0,cnt[100005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(LL i = 1;i <= n;i ++){
		cin >> a; mx = max(mx,a);
		cnt[a] ++;
	}
	for(LL i = 0;i <= mx;i ++) cnt[max(i,mx - i)] --;
	for(LL i = 1;i <= n;i ++) if(cnt[i] < 0){ cout << "Impossible" << endl; return 0; }
	
	for(LL i = 0;i <= ((mx + 1) >> 1);i ++) if(cnt[i] > 0){ cout << "Impossible" << endl; return 0; }

	cout << "Possible" << endl;
	return 0;
}
//