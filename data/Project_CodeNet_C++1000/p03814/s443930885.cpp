#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int main(){
	string s;cin>>s;
	int l=-1,r=-1,ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'&&l==-1){
			l=i;
		}
		else if(s[i]=='Z') r=i;
		if(r>l&&r-l+1>ans) ans=r-l+1;	
	}
	cout<<ans;
	return 0;
}