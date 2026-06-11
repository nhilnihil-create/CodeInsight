#include <iostream>
#include <vector>
#include <string> 
#include <algorithm>
#include <climits>
 
using namespace std;
     
int main() 
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin>>v[i];
		
	int mn = *min_element(v.begin(), v.end());
	int mx = *max_element(v.begin(), v.end());
	
	int ans = INT_MAX;
	for(int i = mn; i <= mx; i++) {
		int sum = 0;
		for(int j = 0; j < v.size(); j++)
			sum += (v[j]-i)*(v[j]-i);
		ans = min(ans, sum);
	}
	cout<<ans;
}