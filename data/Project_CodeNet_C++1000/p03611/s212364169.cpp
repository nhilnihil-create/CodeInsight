#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int cnt[100005];
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		cnt[a-1]++;
		cnt[a]++;
		cnt[a+1]++;
	}
	int ans=-1;
	for(int i=0;i<=1e5;i++) ans=max(ans,cnt[i]);
	cout<<ans;
	re 0;
}