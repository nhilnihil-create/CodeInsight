#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	int a,b;
	cin>>a>>b;
	int arr[a],sum=0;
	for(int i=0;i<a;i++)
		cin>>arr[i];
	sort(arr,arr+a);
	for(int i=a-1;i>a-b-1;i--)
		sum+=arr[i];
	cout<<sum;
	return 0;
}

