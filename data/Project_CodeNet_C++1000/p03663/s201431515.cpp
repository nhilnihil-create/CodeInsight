// ARC 078E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const LL inf = (LL)1000*1000*1000*1000;
int a[22],t;
LL ans;
bool re(LL x)
{
	if(x==0)
		return 1;
	while(t&&x<inf){
		x*=(LL)10;
	}
	cout<<"? "<<(LL)x-t<<endl;
	char c;
	cin>>c;
	if(c=='Y')
		return 1;
	return 0;
}
int main()
{
	int i,j,l;
	LL s;
	t=0;
	s=1;
	for(j=0;j<=10;j=j+1){
		if(!re(s))
			break;
		s*=(LL)10;
	}
	if(j>10){
		s=10;
		while(!re((LL)s-1)){
			s*=(LL)10;
		}
		ans=s/10;
		cout<<"! "<<ans<<endl;
		return 0;
	}
	ans=0;
	t=1;
	l=j;
	for(i=1;i<=l;i=i+1){
		s=(LL)ans*10;
		if(re(s+5)){
			for(j=4;j>=max(1,3-i);j=j-1){
				if(!re((LL)s+j))
					break;
			}
			a[i]=j;
		}
		else{
			for(j=6;j<=9;j=j+1){
				if(re((LL)s+j))
					break;
			}
			a[i]=j-1;
		}
		ans=(LL)s+a[i];
	}
	cout<<"! "<<ans<<endl;
	return 0;
}