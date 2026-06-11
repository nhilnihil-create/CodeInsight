#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL n,l,id = -1;
LL a[200005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> l;
	for(LL i = 1;i <= n;i ++) cin >> a[i];
	for(LL i = 1;i < n;i ++) if(a[i] + a[i + 1] >= l) id = i;
	if(id == -1) cout << "Impossible" << endl;
	else{
		cout << "Possible" << endl;
		for(LL i = 1;i < id;i ++) cout << i << endl;
		for(LL i = n - 1;i > id;i --) cout << i << endl;
		cout << id << endl;
	}
	return 0;
}
//