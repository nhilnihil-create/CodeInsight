//Copyright(c)2017 Mstdream
#include<bits/stdc++.h>
using namespace std;

inline void splay(int &v){
	v=0;char c=0;int p=1;
	while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();}
	while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
	v*=p;
}
#define LL long long
char s[500];
int main(){
	//freopen("xxx.in","r",stdin);
	LL l=10000000000ll,r=99999999999ll;
	while(l!=r){
		LL mid=l+r>>1LL;
		cout<<"? "<<mid<<endl;
		fflush(stdout);
		scanf("%s",s+1);
		if(s[1]=='Y')r=mid;
		else l=mid+1;
	}
	if(l!=10000000000ll){
		l--;
		while(1){
			l/=10;
			cout<<"? "<<l<<endl;
			fflush(stdout);
			scanf("%s",s+1);
			if(s[1]=='Y'){
				cout<<"! "<<l+1<<endl;
				fflush(stdout);
				return 0;
			}
		}
	}
	else{
		l=9;LL ans=1;
		while(1){
			cout<<"? "<<l<<endl;
			fflush(stdout);
			scanf("%s",s+1);
			if(s[1]=='Y'){
				cout<<"! "<<ans<<endl;
				fflush(stdout);
				return 0;
			}
			ans*=10,l*=10;
		}
	}
}	
	