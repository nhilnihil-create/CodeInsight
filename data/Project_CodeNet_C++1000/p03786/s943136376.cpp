#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int res=0;
    char c;
    bool zf=0;
    while(((c=getchar())<'0'||c>'9')&&c!= '-');
    if(c=='-')zf=1;
    else res=c-'0';
    while((c=getchar())>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0';
    if(zf)return -res;
    return res;
}
int _data[100005];
signed main(){
	int n=read();
	for(register int i=1;i<=n;i++){
		_data[i]=read();
	}
	sort(_data+1,_data+n+1);
	long long _sum=0,ans=0;
	for(register int i=1;i<=n;i++){
		_sum+=_data[i];ans++;
		if(_sum*2<_data[i+1])ans=0;
	}
	cout<<ans<<'\n'; 
	return 0;
}