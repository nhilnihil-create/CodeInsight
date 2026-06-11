#include <bits/stdc++.h>
using namespace std;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 998244353
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 200003
#define pc(x) putchar_unlocked(x);
int dep[mx],a[mx];
int n;
string ss;
set<int>isi[30];
int dp(int now){
	if(now==n)return 1;
	if(now==n+1)return 0;
	int&ret=dep[now];
	if(ret!=-1)return ret;
	ret=1e9;
	for(int i=0;i<26;i++){
		auto nxt=isi[i].lower_bound(now);
		ret=min(ret,dp(*nxt+1)+1);
	}
	return ret;
}
vector<int>ans;
void back(int now){
	if(now==n+1)return;
	if(now==n){
		ans.pb(0);
		return;
	}
	int ret=dep[now];
	for(int i=0;i<26;i++){
		auto nxt=isi[i].lower_bound(now);
		if(ret==dp(*nxt+1)+1){
			ans.pb(i);
			back(*nxt+1);
			return;
		}
	}
}

int main(){
	cin>>ss;
	n=ss.length();
	for(int i=0;i<n;i++)a[i]=ss[i]-'a';
	for(int i=0;i<n;i++){
		isi[a[i]].insert(i);
	}
	for(int i=0;i<26;i++)isi[i].insert(n);
	reset(dep,-1);
	int jaw=dp(0);
	back(0);
	for(int i:ans){
		char a=i+'a';
		cout<<a;
	}
}


