#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 5e5+10;
const ll mod = 998244353;
ll n;
pair<ll,ll>  arr[N];
ll a[N];ll cnt;ll mn=N;
int main()
{  fast
cin>>n;
for(int i=1;i<=n;i++){
cin>>arr[i].fi;arr[i].se=i;}
sort(arr+1,arr+n+1);
for(int i=n;i;i--){
	cnt++;
	mn=min(mn,arr[i].se);
	if(arr[i].fi!=arr[i-1].fi)
	a[mn]+=abs(arr[i].fi-arr[i-1].fi)*cnt;
}
for(int i=1;i<=n;i++)
cout<<a[i]<<"\n";
}