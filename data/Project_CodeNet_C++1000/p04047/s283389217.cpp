#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
using namespace std;
int a[10000000];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main(){
    int T=read();
    for(int i=0;i<2*T;i++){
    	a[i]=read();
	}
	sort(a,a+2*T);
	long long ans=0;
	for(int i=0;i<2*T;i=i+2)
	{
		ans=ans+min(a[i],a[i+1]);
	}
	cout<<ans<<endl;
 	return 0;
} 