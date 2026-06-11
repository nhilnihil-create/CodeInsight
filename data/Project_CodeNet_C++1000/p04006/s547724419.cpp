#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define int long long
int N , X , arr[100003] , mn[100003];

signed main(){
	cin >> N >> X;
	for(int i = 0 ; i < N ; ++i){cin >> arr[i]; arr[i + N] = arr[i];}
	int ans = 1e18; memset(mn , 0x3f , sizeof(mn));
	for(int i = 0 ; i <= N ; ++i){
		for(int j = 0 ; j < N ; ++j)
			mn[(i + j) % N] = min(mn[(i + j) % N] , arr[j]);
		int sum = i * X; for(int j = 0 ; j < N ; ++j) sum += mn[j];
		ans = min(ans , sum);
	}
	cout << ans; return 0;
}