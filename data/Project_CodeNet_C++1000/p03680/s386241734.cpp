#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
int main(){
	fast;
	ll n,s=1,cnt=0,next=0,prev=0;
	cin>>n;
	int arr[n+1],fr[n+1]={0};
	for(int i=1;i<n+1;i++)
		cin>>arr[i];
	while(1){
		fr[s]++;
		if(fr[s]>1)
			break;
		s=arr[s];
		cnt++;
		if(s==2)
		{
			cout<<cnt;
			return 0;
		}
		
	}
	cout<<-1;
	return 0;
}

