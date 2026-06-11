#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	ll A[100001];
	A[0] = 0;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> A[i];
	}
	
	ll ans = 0;
	for(int i =1; i <= N; i++){
		if(A[i-1] == 1){
			if(A[i] > 0){
				ans++;
				A[i]--;
			}
		}
		ans += A[i]/2;
		A[i] -= (A[i]/2)*2;
	}
	cout << ans << endl;
	
	return 0;
}