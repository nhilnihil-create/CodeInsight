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
string a,ans;
int main(){
	int n,s=0;cin>>n>>a;ans=a;
	for(int i=0;i<a.size();i++){
		s+=(a[i]=='(')?1:-1;
		if(s<0) ans='('+ans,s++;
	}
	while(s--) ans=ans+')';
	cout<<ans; 
}