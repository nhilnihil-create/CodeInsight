#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)

const int MAX=2e5+5;

int n,m,a[MAX];
int line[MAX];

inline int read();
bool judge(int);

int main(){

	n=read(); m=(n<<1)-1; lor(i,1,m) a[i]=read();

	int l=1,r=m;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)) l=mid+1;
		else r=mid-1;
	}	
	printf("%d\n",r);
	
	return 0;
}

inline int read(){
	char tmp=getchar(); int sum=0; bool flag=false;
	while(tmp<'0'||tmp>'9'){
		if(tmp=='-') flag=true;
		tmp=getchar();
	}
	while(tmp>='0'&&tmp<='9'){
		sum=(sum<<1)+(sum<<3)+tmp-'0';
		tmp=getchar();
	}
	return flag?-sum:sum;
}

bool judge(int mid){
	lor(i,1,m) line[i]=(a[i]>=mid);
	int l,r; l=r=n;
	while(l>1&&r<m){
		if(line[l-1]==line[l]||line[r]==line[r+1]) return line[l];
		l--; r++;
	}
	return line[1];
}