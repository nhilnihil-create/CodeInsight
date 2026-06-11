//arc082_d.cpp
//Sat Jul 20 19:04:48 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	vector<int> nums;
	for (int i=0;i<n;i++){
		int temp;
		cin >> temp;
		if (temp == i+1){
			nums.push_back(i+1);
		}
	}

	if (nums.size()==0){
		cout << "0" << endl;
		return 0;
	}

	int ans = 0;
	int i=0;
	for (i=0;i<nums.size()-1;i++){
		if (nums[i]+1==nums[i+1]){
			i++;
		}
		ans++;
	}

//	cout << i << endl;

	if (i==nums.size()-1){
		ans++;
	}

	cout << ans << endl;
//	printf("%.4f\n",ans);
}