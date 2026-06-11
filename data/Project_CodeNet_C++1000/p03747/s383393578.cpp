#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL dir,pos[200005];
LL n,l,t,rnk = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> l >> t;
	for(LL i = 1;i <= n;i ++){
		cin >> pos[i] >> dir;
		if(dir == 1){
			pos[i] += t;
			rnk += pos[i] / l;
		}
		else{
			pos[i] -= t;
			rnk += (pos[i] >= 0 ? 0 : (pos[i] + 1 - l) / l);
		}
		pos[i] = (pos[i] % l + l) % l;
		rnk = (rnk % n + n) % n;
	}
	sort(pos + 1,pos + 1 + n);
	for(LL i = rnk + 1;i <= n;i ++) cout << pos[i] << endl;
	for(LL i = 1;i <= rnk;i ++) cout << pos[i] << endl;
    return 0;
}
//