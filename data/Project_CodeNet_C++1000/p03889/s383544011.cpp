#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define oo (1e18)
#define ll long long
#define LL unsigned long long
#define hh puts("")
using namespace std;
string a,b;
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
    return ret*ff;
}
signed main(){
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());
	for(int i=0;i<a.size();i++){
		if(a[i]=='p') a[i]='q';
		else if(a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		else if(a[i]=='q') a[i]='p';
	}
	if(a==b) printf("Yes");
	else printf("No");
    return 0;
}