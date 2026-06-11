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
string s;
int cnt[26];
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<sz(s);i++) cnt[s[i]-'a']++;
	for(int i=0;i<26;i++){
		if(cnt[i]>1){
			cout<<"no";
			re 0;
		}
	}
	cout<<"yes";
	re 0;
}