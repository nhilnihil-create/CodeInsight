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

using namespace std;

#define mod 1000000007

int main()
{
	long long int n;
	cin >> n;
	long long int tmp;
	vector<int> ans;
	for(int i = 40; i >= 0; i--){
		if(n >= (long long int)pow(2, i) - 1){
			tmp = i;
			n -= (long long int)pow(2, i) - 1;
			break;
		}
	}
	for(int i = 0; i < 2; i++){
		for(int j = 1; j <= tmp; j++){
			ans.push_back(j);
		}
	}
	for(int i = tmp - 1; i >= 0; i--){
		if(n >= (long long int)pow(2, i)){
			n -= (long long int)pow(2, i);
			tmp++;
			ans.insert(ans.begin() + i, tmp);
			ans.push_back(tmp);
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i == ans.size() - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}