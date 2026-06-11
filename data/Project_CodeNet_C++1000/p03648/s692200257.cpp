#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

vector<long long int> solve(long long int k)
{
	vector<long long int> result;
	if(k == 0){
		result.push_back(0);
		result.push_back(0);
	} else if(k == 1){
		result.push_back(0);
		result.push_back(2);
	} else if(k <= 50){
		for(int i = 0; i < k; i++){
			result.push_back(i + 1);
		}
	} else {
		long long int tmp1 = k / 50;
		long long int tmp2 = k % 50;
		// cout << tmp1 << endl;
		for(int i = 0; i < 50; i++){
			result.push_back(tmp1 + i);
		}
		for(int i = 0; i < tmp2; i++){
			for(int j = 0; j < 50; j++){
				if(i == j) result[j] += 50;
				else result[j]--;
			}
		}
	}
	return result;
}

int main()
{
	long long int k;
	cin >> k;
	// cout << k << endl;
	vector<long long int> ans = solve(k);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i == ans.size() - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}
