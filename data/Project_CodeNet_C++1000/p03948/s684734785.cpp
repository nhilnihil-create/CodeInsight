#include <iostream>
#include <map>
using namespace std;
#define ll long long
map<ll,ll> chk;
ll arr[100001],N,M,mi=2100000000,dis,ans;
int main()
{
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
	{
		cin >> arr[i];
		chk[arr[i]]=i+1;
		
		if(arr[i]-mi>dis)
		dis=arr[i]-mi;
		if(mi>arr[i])
		mi=arr[i];
	}
	for(int i=0; i<N; i++)
	{
		if(chk[arr[i]-dis]<i+1&&chk[arr[i]-dis])
		ans++;
	}
	cout << ans;
	
}