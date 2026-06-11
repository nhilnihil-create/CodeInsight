#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long,int> a[100004];
long long ans[100004];
bool cmp(pair<long long,int> a, pair<long long,int> b){
	if(a.first == b.first)	return a.second<b.second;
	return a.first>b.first;
}

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i].first;
		a[i].second = i;
	}
	a[0].first = 0;
	a[0].second = 0;
	sort(a,a+n+1,cmp);
	memset(ans,0,sizeof(ans));
	for(long long i = 0 ; i <= n ;){
		if(a[i].second == 0){
			break;
		}
		long long ret = 0;
		long long next;
		for(long long j = i+1;j<=n;j++){
			ret += j*(a[j-1].first-a[j].first);
			if(a[j].second<a[i].second){
				next = j;
				break;
			}
		}
		ans[a[i].second] = ret;
		i = next;
	}
	for (int i = 1 ; i<=n;i++)	cout<<ans[i]<<'\n';
	return 0;
}