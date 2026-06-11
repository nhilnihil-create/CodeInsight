#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0; char c=getchar(); int flag=1;
	while(!isdigit(c)) { if(c=='-') flag=-1; c=getchar(); }
	while(isdigit(c)) { x=((x+(x<<2))<<1)+(c^48); c=getchar(); }
	return x*flag;
}

const int N=200000;
int n;
int a[N+5];
int t[N+5];

set<int> s;
set<int>::iterator it1,it2;

signed main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),t[a[i]]=i;
    
    s.insert(0); s.insert(n+1);
    long long ans=0;
    
    for(int i=1;i<=n;i++){
	    it2=it1=s.lower_bound(t[i]);
	    it1--;
	    ans+=1ll*i*(t[i]-*it1)*(*it2-t[i]);
	    s.insert(t[i]);
	}
	printf("%lld\n",ans);
    return 0;
}