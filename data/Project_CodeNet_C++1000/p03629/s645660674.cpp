#include<bits/stdc++.h>
using namespace std;

const int N=200100;
int n,f[N],lst[N][26];
char s[N];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;n=strlen(s);
	f[n]=1;fill(lst[n],lst[n]+26,n);
	for(int i=n-1;~i;--i){
		memcpy(lst[i],lst[i+1],sizeof lst[i+1]);
		lst[i][s[i]-'a']=i;
		f[i]=n+1;
		for(int j=0;j<26;++j)f[i]=min(f[i],f[lst[i][j]+1]+1);
	}
	for(int len=f[0],i=0;len --> 0;){
		for(int j=0;j<26;++j)if(f[lst[i][j]+1]+1==f[i]){
			cout<<char('a'+j);i=lst[i][j]+1;
			break;
		}
	}
	cout<<'\n';
	return 0;
}
