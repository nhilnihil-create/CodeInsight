#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a,a+n);
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=(i+a[i].second)&1;
	cout<<(cnt>>1)<<endl;
}
