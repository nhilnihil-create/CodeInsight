#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
//deque/functional/iterator/list/map/memory/numeric/queue/set/stack/utility/vector
//#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000000];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	ll s=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	ll k=0;
	ll mi=1e16;
	for(int i=0;i<n-1;i++){
		k+=a[i];
		if(abs(s-2*k)<=mi){
			mi=abs(s-2*k);
		}
	}
	cout<<mi<<endl;
return 0;
}
