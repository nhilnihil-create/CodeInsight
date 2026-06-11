//Wrong answer on test inf.
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
using namespace std;
char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
ll read(){
	char ch=gc();ll x=0;int op=1;
	for (;!isdigit(ch);ch=gc()) if (ch=='-') op=-1;
	for (;isdigit(ch);ch=gc()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
int len;
string s,typ,ans;
void ask(string x){
	cout<<"? "+x<<'\n';
	fflush(stdout);
	cin>>typ;
}
void print(string s){
	cout<<"! "+s<<'\n';
	fflush(stdout);
	exit(0);
}
int init(){
	s="10";
	rep (i,1,9){
		ask(s);if (typ=="N") return i;s+='0';
	}
	s="9";
	rep (i,1,9){
		ask(s);if (typ=="Y") return i;s+='9';
	}
	return 10;
}
bool check(int x,int y){
	s=ans+char(x+'0');
	ask(s);
	return typ=="Y";
}
int main(){
	len=init();
	if (len==10) return printf("! 1000000000\n"),0;
	ans="";
	rep (i,1,len-1){
		int l=i==1,r=9,mid,t=0;
		while (l<=r){
			mid=l+r>>1;
			if (check(mid,i)) t=mid,l=mid+1;else r=mid-1;
		}
		ans+=char(t+'0');
	}
	rep (i,(len==1?1:0),9){
		s=ans+(char(i+'0'))+'0';
		ask(s);
		if (typ=="Y") print(ans+char(i+'0'));
	}
	return 0;
}
