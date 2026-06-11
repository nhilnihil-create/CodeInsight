#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>s;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	ll n=gi()+1;int o=0;
	s.push_back(++o);
	int flg=-1;
	for(int i=39;~i;--i)
		if((n>>i)&1){
			if(flg==-1)flg=i;
			else{
				if(flg!=i+1)s.push_back(++o);
				s.insert(s.begin(),++o);
			}
		}else if(~flg&&flg!=i+1)s.push_back(++o);
	printf("%d\n",s.size()*2);
	for(int i:s)printf("%d ",i);
	for(int i=1;i<=o;++i)printf("%d ",i);
	return 0;
}
