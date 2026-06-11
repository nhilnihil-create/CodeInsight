#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define endl '\n'
using namespace std;
int arr[maxn];
ll ans[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	vector<int> idxs(n);
	iota(idxs.begin(),idxs.end(),1);
	sort(idxs.begin(),idxs.end(),[=](int a,int b)->bool
		{return arr[a] != arr[b] ? arr[a] > arr[b] : a < b;});
	arr[n+1] = 0;
	idxs.emplace_back(n+1);

	ll sum = 0;
	int idx = n + 1;
	for(int i=0;i<n;) {
		idx = min(idx,idxs[i]);
		int j = i;
		for(;j<n && arr[idxs[j]] == arr[idxs[i]];j++)
			sum++;
		ans[idx] += sum * (arr[idxs[i]] - arr[idxs[j]]);
		i = j;
	}
	
	for(int i=1;i<=n;i++)
		cout << ans[i] << endl;
	return 0;
}
