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
int cnt[105];
signed main(){
	ios_base::sync_with_stdio(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int ans=0;
	for(int i=a+1;i<=b;i++) cnt[i]++;
	for(int i=c+1;i<=d;i++) cnt[i]++;
	for(int i=1;i<=100;i++) if(cnt[i]==2) ans++;
	cout<<ans;
	re 0;
}