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
int n;
string s;
bool used[105];
int cnt1,cnt2;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='('&&!used[i]){
			used[i]=1;
			bool found=0;
			for(int j=i+1;j<n;j++){
				if(s[j]==')'&&!used[j]){
					used[j]=1;
					found=1;
					break;
				}
			}
			if(!found) cnt2++;
		}
		if(s[i]==')'&&!used[i]){
			used[i]=1;
			bool found=0;
			for(int j=i-1;j>=0;j--){
				if(s[j]=='('&&!used[j]){
					used[j]=1;
					found=1;
					break;
				}
			}
			if(!found) cnt1++;
		}
	}
	for(int i=0;i<cnt1;i++) cout<<'(';
	cout<<s;
	for(int i=0;i<cnt2;i++) cout<<')';
	re 0;
}