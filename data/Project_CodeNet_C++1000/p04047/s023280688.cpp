#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
int main() {
	int N;
	cin >> N;
	for(int i=0;i<2*N;i+=1){
	     int x;
	     cin >> x;
	     v.push_back(x);
	}
	sort(v.begin(),v.end());
	int a = floor(N/2);
	int ans = 0;
	for(int i=0;i<(N*2);i+=2){
	     ans+=v[i];
	    // cout << v[i]<<endl;
	}
	cout << ans;
	return 0;
}
