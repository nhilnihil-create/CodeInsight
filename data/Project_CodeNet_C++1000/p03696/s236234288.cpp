#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+6;
int a[N];
void solve(){
	int n; 
	cin>>n; 
	string s; 
	cin>>s; 
	int cnt = 0;
	int mn = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='(')cnt++;
		else cnt--;
		mn = min(mn,cnt);
	}
	mn = -mn;
	string ss = "";
	for(int i=0;i<mn;i++)ss+='(';
	for(int i=0;i<n;i++)ss+=s[i];
	cnt = 0;
	n = ss.size();
	for(int i=0;i<n;i++){
		if(ss[i]=='(')cnt++;
		else cnt--;
	}
	for(int i=0;i<cnt;i++){
		ss+=')';
	}
	cout<<ss<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
