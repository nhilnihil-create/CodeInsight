#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0;i < N;i++)cin >> a[i];

	sort(a.begin(),a.end());

	if(a[0] == a[N-1]){
		if(a[0] == N - 1 || a[0] * 2 <= N){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	else{
		if(a[0] != a[N-1] - 1){
			cout << "No" << endl;
			return 0;
		}
		
		int num = a[0];
		int id = 0;
		while(id < N && a[id] == num){
			id++;
		}

		int group_num = num + 1;

		if(group_num - id <= 0 || !(N - id >= 2 * (group_num - id))){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
}
