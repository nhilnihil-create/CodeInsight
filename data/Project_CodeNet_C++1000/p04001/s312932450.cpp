#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define re return
#define all(a) a.begin(),a.end()
#define int long long
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
vector<int>v;
int ans;
void dfs(){
	int last=v[sz(v)-1];
	int ans1=0;
	for (int i=0;i<sz(v);i++){
		ans1+=v[i];
	}
	ans+=ans1;//cout<<ans1<<'+';
	v.erase(v.end()-1);
	int num;
	for (num=10;;num*=10){
		if (num>=last)  break;
		int a=last/num;
		int b=last%num;
		v.pb(a), v.pb(b);
		dfs();
		v.erase(v.end()-1); 
		v.erase(v.end()-1); 
	}
	v.pb(last);
}
signed main()
{
	int s;
	cin>>s;
	v.pb(s);
	dfs();
	cout<<ans;
	re 0;
}
