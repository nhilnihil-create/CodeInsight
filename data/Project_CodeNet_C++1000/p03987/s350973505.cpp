#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long long int n, arr[200010], cvp;
vector<pair<long long int, long long int> > something;
set<long long int> step;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long int i=1;i<=n;i++){
		cin>>arr[i];
		something.push_back(make_pair(arr[i], i));
	}
	sort(something.begin(), something.end());
	cvp=something[0].second*(n-something[0].second+1);
	step.insert(something[0].second);
	for (long long int i = 1; i < n; ++i){
		long long int bas, son;
		set<long long int>::iterator it=step.lower_bound(something[i].second);
		if(it==step.end())son=n+1;
		else son=*it;
		if(it==step.begin())bas=0;
		else{
			it--;
			bas=*it;
		}
		cvp+=something[i].first*(something[i].second-bas)*(son-something[i].second);
		step.insert(something[i].second);
	}
	cout<<cvp;
	return 0;
}