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
int a[26];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		a[s[i]-'a']++;
	int ok=1;
	//for(int i=0;i<26;i++) printf("%d %d\n",i,a[i]);
	for(int i=0;i<26;i++)
		if(a[i]&1) {
			ok=0;
			break;
		}
		puts(ok?"Yes":"No");
	return 0;
}