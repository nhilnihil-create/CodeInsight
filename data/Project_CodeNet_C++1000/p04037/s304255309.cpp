//Achen
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e5+7;
typedef long long LL; 
typedef double db;
using namespace std;
int n,a[N],fl1,fl2,sum;

template<typename T> void read(T &x) {
    char ch=getchar(); x=0; T f=1;
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') f=-1,ch=getchar();
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0'; x*=f;
}

bool cmp(const int &A,const int &B) {
	return A>B;
}

//#define DEBUG
int main() {
#ifdef DEBUG
	freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	read(n);
	For(i,1,n) read(a[i]);
	sort(a+1,a+n+1,cmp);
	For(i,1,n) {
		if(a[i+1]<i+1) {
			i--;
			int j=i; while(a[j+1]>i) j++;
			if(((a[i+1]-i)&1)&&((j-i)&1)) puts("Second");
			else puts("First"); 
			break;
		}
	}
    return 0;
}