/*=================================
# Created time: 2017-04-05 11:23
# Filename: c.cpp
# Description: 
=================================*/
#include <bits/stdc++.h> 
 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
#define lb lower_bound 
#define ub upper_bound 
#define sqr(x) (x)*(x) 
#define lowbit(x) (x)&(-x) 
#define pii pair<int, int> 
#define ls(a,b) (((a)+(b)) << 1) 
#define rs(a,b) (((a)+(b)) >> 1) 
#define fin(a) freopen(a,"r",stdin); 
#define fout(a) freopen(a,"w",stdout); 
#define FORP(i,a,b) for(int i=(a);i<=(b);i++) 
#define FORM(i,a,b) for(int i=(a);i>=(b);i--) 
 
#define maxn 100005 
#define maxm 100005 
#define MOD 1000000007 
#define INF 1070000000 
using namespace std; 
typedef long long ll; 
typedef unsigned long long ull; 
 
template<class T> inline   
void read(T& num){   
    num = 0; bool f = 1;char ch = getchar();   
    while(ch < '0' || ch > '9') { if(ch == '-') f = 0;ch = getchar();}   
    while(ch >= '0' && ch <= '9') {num = num * 10 + ch - '0';ch = getchar();}   
    num = f ? num: -num;   
}  
template<class T> inline 
void write(T x,char ch){ 
	int s[100]; 
	if (x==0) {putchar('0'); putchar(ch); return;} 
	if (x<0) {putchar('-'); x=-x;} int num=0; 
	while (x){ s[num++]=(x%10); x=x/10;} 
	FORM(i,num-1,0) putchar(s[i]+'0'); putchar(ch); 
} 
/*==================split line==================*/ 
const double pi = acos(-1); 
const double eps = 1e-8; 
int a[maxn];
int main(){ 
	ll n; read(n); n++;
	memset(a, 0x7f, sizeof(a));
	int head = 1, tail = 100, top = INF;
	while (n > 1){
		if (n & 1){
			a[head++] = top--; n --;
		}
		else {
			a[tail--] = top--; n >>= 1; 
		}
	}
	write((INF - top) * 2,'\n');
	FORP(i, 1, 100) if (a[i] <= INF) write(a[i] - top,' ');
	FORP(i, top + 1, INF) write(i - top,' '); puts("");

}
