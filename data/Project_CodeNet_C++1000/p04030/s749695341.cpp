#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
char ans[N];
int main(){
	string s;
	cin>>s;
	int n=s.size();
	int x=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') ans[++x]='0';
		else if(s[i]=='1') ans[++x]='1';
		else if(s[i]=='B'&&x){
			x--;
		}
	}
	for(int i=1;i<=x;i++) cout<<ans[i];
	cout<<ans;
	return 0;
}