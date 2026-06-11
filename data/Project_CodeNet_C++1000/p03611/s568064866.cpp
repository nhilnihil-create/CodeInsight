/// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	int n;
	cin>>n;
	map<int,int> mp;
	int a[n];
	int x=INT_MAX;
	int end = INT_MIN;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>end) end=a[i];
		if(a[i]<x) x = a[i];
		mp[a[i]]++;
	}
	int ans=0;
	for(int i=x;i<=end;i++){
		int sum = mp[i-1]+mp[i]+mp[i+1];
		if(sum>ans) ans = sum;
	}
	cout<<ans<<endl;

	//cout<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}