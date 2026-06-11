#include<bits/stdc++.h>
using namespace std;
int bit[200003],n,k;
pair<long long,int>a[200003]; 
int sum(int x){
	int ret=0;
	for(;x>=1;x-=x&(-x))ret+=bit[x];
	return ret;
}
void add(int x){
	for(;x<n+2;x+=x&(-x))bit[x]++; 
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].first),a[i].first-=k,a[i].second=i+1;
	for(int i=0;i<n;i++)a[i+1].first+=a[i].first;
	for(int i=n;i>=0;i--)a[i+1]=a[i];
	a[1].second=1;
	sort(a+1,a+n+2);
	long long ans=0;
	for(int i=1;i<=n+1;i++){
		ans+=sum(a[i].second);
		//cout<<a[i].second<<' '<<sum(a[i].second)<<endl;
		add(a[i].second);
	}
	cout<<ans;
} 