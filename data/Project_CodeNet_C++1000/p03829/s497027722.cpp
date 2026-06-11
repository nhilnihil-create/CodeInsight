#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long LL;

LL n,A,B,ans = 0;
LL x[500005] = {0};
 
int main(){
	cin >> n >> A >> B;
	cin >> x[1];
	for(LL i = 2;i <= n;i ++){
		cin >> x[i];
		ans += min((x[i] - x[i - 1]) * A,B);
	}
	cout << ans << endl;
	return 0;
}