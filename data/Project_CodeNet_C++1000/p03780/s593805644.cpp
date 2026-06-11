#include <bits/stdc++.h>

using namespace std;

const int N = 3*100000 + 1;

const int K = 5000;

int n , k,a[N];

bitset<K> pre[N+1],suf[N+1];


int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		scanf("%d",a+i);
	}
	pre[0][0] = 1;
	for(int i = 1; i <= n;++i){
		pre[i] = (pre[i-1] << a[i]) | pre[i-1];
	}
	suf[n+1][0] = 1;
	for(int i = n; i >= 1;--i){
		suf[i] = (suf[i+1] << a[i]) | (suf[i+1]);
	}

	int ans = 0;
	for(int i = 1; i <= n;++i){
		vector<int> v1,v2;
		for(int j = 0; j < k;++j){
			if(suf[i+1][j])v1.push_back(j);
			if(pre[i-1][j])v2.push_back(j);
		}
		int idx = 1;
		bool imp = false;
		for(int j = v2.size()-1;j>= 0;--j){
			while(idx < v1.size() && v1[idx]+v2[j] < k-a[i])idx++;
			int current = (idx == v1.size()?idx-1:idx);	
			if(v1[current]+v2[j] < k && v1[current]+v2[j]+a[i] >= k){
				imp = true;
			}
		}
		if(imp){
			ans++;
		}
	}
	ans = n-ans;
	cout << ans << endl;

	return 0;
}

