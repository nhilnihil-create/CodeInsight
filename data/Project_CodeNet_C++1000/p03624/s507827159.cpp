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
bool visited[27]; 
signed main(){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	for(int i=0;i<sz(s);i++) visited[s[i]-'a']=1;
	for(int i=0;i<26;i++){
		if(!visited[i]){
			cout<<char(i+'a');
			re 0;
		}
	}
	cout<<"None";
	re 0;
}