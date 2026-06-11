#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;

int main(){
	int n,t; cin >> n >> t;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int cnt=0;
	int ma=0;
	int ans=0;
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0;i<n;i++){
		q.push(a[i]);
		if(a[i]-q.top()==ma&&ma){
			cnt++;
		}
		else if(a[i]-q.top()>ma){
			ma=a[i]-q.top();
			ans=max(ans,cnt);
			cnt=1;
		}
	}
	ans=max(ans,cnt);
	cout << ans << endl;
}