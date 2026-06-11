#include<bits/stdc++.h>
#define  fuckit(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
int main()
{
	fuckit();
	ll n,x,i,cnt=0,t;
	cin>>n>>x;
	int ara[n];
	for(i=0;i<n;i++){
		cin>>ara[i];
	}
	for(i=0;i<n-1;i++){
		t=ara[i]+ara[i+1];
		if(t>x){
			t=t-x;
			cnt+=t;
			if(ara[i+1]<t){
				t-=ara[i+1];
				ara[i+1]=0;
			}
			else{
				ara[i+1]-=t;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;	
}
