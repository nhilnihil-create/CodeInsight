/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int lowbit(int x){return x&-x;}
const int N=200000;
int n,m;
int a[N+1];
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
	for(int i=0;i<=n;i++)a[i]=lower_bound(nums.begin(),nums.end(),a[i]-i*m)-nums.begin()+1;
}
struct bitree{
	int sum[N+2];
	void init(){memset(sum,0,sizeof(sum));}
	void add(int x){
		while(x<=n+1)sum[x]++,x+=lowbit(x);
	}
	int Sum(int x){
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}bit;
signed main(){
	cin>>n>>m;
	nums.pb(0);
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=a[i-1],nums.pb(a[i]-i*m);
//	for(int i=0;i<=n;i++)cout<<a[i]-i*m<<" ";puts("");
	discrete();
//	for(int i=0;i<=n;i++)cout<<a[i]<<" ";puts("");
	int ans=0;
	bit.init();
	bit.add(a[0]);
	for(int i=1;i<=n;i++){
		ans+=bit.Sum(a[i]); 
		bit.add(a[i]);
	}
	cout<<ans;
	return 0;
}