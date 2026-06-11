#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
#define pr pair<int,int>
#define all vec.begin(),vec.end()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define fi first
#define se second
#define pushb push_back
#define makep make_pair

using namespace std;

int main(){
	int n;
	cin >> n;
	int j=0,m;
	int arr[n];
	while(cin >> m)
		arr[j++] = m;
	sort(arr,arr+n);
	int min = 2e8;
	int ret = arr[0];
	for(int i = arr[0]; i < arr[n-1]; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			int diff = arr[j] - i;
			diff *= diff;
			sum += diff;
		}
		if(sum < min)
			min = sum, ret = i;
	}
	if(min == 2e8)
		cout << 0;
	else
		cout << min;
	return 0;
}

