#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

int n,a,b,mn,mx;

void GG(){
	puts("No"),exit(0);
}
void owo(){
	puts("Yes"),exit(0);
}

int main(){
	read(n);
	mn=n,mx=0;
	rep(i,1,n){
		int x; read(x);
		if(x<mn) mn=x,a=0;
		if(x>mx) mx=x,b=0;
		a+=(mn==x);
		b+=(mx==x);
	}
	if(mx-mn>=2) GG();
	if(mn==mx){
		if(mn==n-1) owo();
		if(mx*2>n) GG();
		owo();
	}
	if(mn<a) GG();
	if(b<(mx-a)*2) GG();
	owo();
	return 0;
}