#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll counter[mx] = {0};
int main()
{	
	ios_base::sync_with_stdio(0);
	ll n,value,copy,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>value>>copy;
		counter[value]+=copy;
	}
	ll sum = 0;
	for(int i=0; i<mx; i++){
		sum+=counter[i];
		if(sum>=k){
			cout<<i<<endl;
			return 0;
		}
	}
}