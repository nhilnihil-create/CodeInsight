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
signed main(){
	int n=read(),ans=0;
	while(n--)ans+=(read()&1);
	if(ans&1)puts("NO");
	else puts("YES");
	return 0;
}