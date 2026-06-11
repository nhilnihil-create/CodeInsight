#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
const int maxn=2e5+5;
int n,nxt[maxn][26],f[maxn];
string s;
int main(){
	cin>>s;s=' '+s;n=s.size()-1;
	memset(nxt,-1,sizeof(nxt));
	for(int i=n;i>0;i--)
		for(int j=0;j<26;j++)
			nxt[i][j]=(s[i]==j+'a'?i:nxt[i+1][j]);
	memset(f,0x3f,sizeof(f));
	for(int i=n;i>0;i--){
		for(int j=0;j<26;j++){
			if(nxt[i][j]==-1){f[i]=1;break;}
			f[i]=min(f[i],f[nxt[i][j]+1]+1);
		}
	}
	int len=f[1],pos=1;
	while(len--){
		if(!len)for(int i=0;i<26;i++)
				if(nxt[pos][i]==-1)return 0*putchar(i+'a');
		for(int i=0;i<26;i++)
			if(f[pos]==f[nxt[pos][i]+1]+1){
				pos=nxt[pos][i]+1;
				putchar(i+'a');break;
			}
	}
	return 0;
}