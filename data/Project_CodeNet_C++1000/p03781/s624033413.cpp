#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll x;

int main(){
	cin >> x;
	ll height = 0;
	ll ans = 0;
	
	while(height < x){
		ans++;
		height += ans;
	}
	
	cout << ans << endl;
	return 0;
}