#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isneed(vector<int>& a,int it,int n,int k){
	vector<bool> dp(k+5,false);
	dp[0]=true;
	for(int i=0;i<n;i++){
		if(i==it) continue;
		for(int j=k;j>=a[i];j--){
			if(dp[j-a[i]]) dp[j]=true;
		}
	}
	for(int i=max(0,k-a[it]);i<k;i++) if(dp[i]) return true;
	return false;
}

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end(),greater<int>());
	int left=-1,right=n;
	while(right-left>1){
		int mid=(right+left)/2;
		if(isneed(a,mid,n,k)) left=mid;
		else right=mid;
	}
	int ans=n-(left+1);
	cout << ans << endl;
	return 0;
}
