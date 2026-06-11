#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL cnt[8];
LL tot1 = 0,tot2 = 0;

int main(){
	for(LL i = 1;i <= 7;i ++) cin >> cnt[i];
	tot2 += (cnt[2] << 1) + ((cnt[1] >> 1) << 2) + ((cnt[4] >> 1) << 2) + ((cnt[5] >> 1) << 2);
	if(cnt[1] && cnt[4] && cnt[5]){
		cnt[1] --; cnt[4] --; cnt[5] --;
		tot1 = 6;
		tot1 += (cnt[2] << 1) + ((cnt[1] >> 1) << 2) + ((cnt[4] >> 1) << 2) + ((cnt[5] >> 1) << 2);
	}
	cout << (max(tot1,tot2) >> 1) << endl;
	return 0;
}