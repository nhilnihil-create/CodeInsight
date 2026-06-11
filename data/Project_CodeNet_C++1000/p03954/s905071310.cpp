#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
//window
//scanf
//stdio.h>cstdio
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define wi(x) while(x)
#define fl(i,l,r) for(register int i=(l);i<(r);++i)
#define xfl(i,x,l,r) int *lf=&x[l],*rf=&x[r]; for(register int *i=(lf);i<(rf);++i)
#define xpfl(lf,rf,p,i,x,l,r) p *lf=&x[l],*rf=&x[r]; for(register p *i=(lf);i<(rf);++i)
#define fr(i,r,l) for(register int i=(r-1);i>=(l);--i)
#define ksm(i,x) for(register int i=0;x;x>>=1,i++)
#define pq priority_queue
#define xg(i) vector<i>,greater<i> 
#define fbo friend bool operator 
#define vpb push_back
#define vpp pop_back()
#define ppb push
#define ppp pop()
#define sz size()
#define fun(x) std::cerr << #x << ':' << ' '
#define fu(x) std::cerr << #x << ' '
#define de(x) std::cerr << #x << '=' << x << ' '
#define pi(x) cerr << x <<' ' 
#define petr printf("\n");
#define qwq printf("qwq\n");
#define fmnt 0x3fffffff
#define mnt 0x7fffffff  
#define ll long long
#define mod 
#define maxn 
using namespace std;
/*模板规定:
    1.常使用函数名称固定， 有不同模板库（可建立） 
    2.函数进入模板符合三个条件：
	    （1）正确，得到oj题目验证
		（2）实用，某部分常使用
		（3）在附带注释中注明用途 
	3.模板必须背过 
    4.一般变量名称、define固定含义，如下： 
    #define ll long long
    #define mod //模数 
    #define maxn //n数组大小 或n最大值
	a b c d 函数参数
	x y 变量
	n m t 数据相关
	u v 累计数据
	i j k w 循环
	r ans 返回值
	temp 临时中间变量 
*/ 
//window read()>scanf()
//linux read()<scanf()
template <class T> inline void read(T &x) {
	//读入整型数据 
	x=0;
	char ch=getchar(),w=0;
	while (!isdigit(ch)) w=(ch=='-'),ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x=w?-x:x;
	return;
}
template <class T> inline T maxx(T a,T b){
	//取最大值 
	return a>b?a:b;
}
template <class T> inline T minn(T a,T b){
	//取最小值 
	return a>b?b:a;
}
template <class T> inline void swapp(T &a,T &b){
	//交换单个同类数据 
	T c=a;a=b,b=c;
}
template <class T> inline T abss(T a){
	//取绝对值 
	return a?a:(-a);
}
template <class T> inline void piz(T *a,int siza){
	xfl(i,a,0,siza) cerr<<*i<<' ';
	petr;
}
inline int random(int l,int r){
	return (((rand()<<30)+(rand()<<15)+rand())%(r-l+1)+l);
}
inline int randf(int x,int y){
	return random(1,y)<=x;
}
ll n;
vector<ll> a;
ll ans;
void scan(){
	ll x;
	read(n);
	n=(n<<1)-1;
	fl(i,0,n) read(x),a.vpb(x);
}
bool calc(ll z){
	int mid=(n>>1);
	int x,y;
	bool i,j;
	x=mid-1,y=mid+1;
	bool c=(a[mid]>=z);
	wi(y<n){
		i=(a[x]>=z),j=(a[y]>=z);
		if(i==j){
			if(i==c) {/*fu(return:0),pi(c);*/return c;}
	        else c=i; 
		}
		else{
			{/*fu(return:1),pi(c);*/return c;}
		}
		x--,y++; 
	}
	{/*fu(return:2),pi(c);*/return c;}
}
ll erfen(){
	ll l=1,r=n;
	int mid;
	wi(l!=r-1){
		mid=(l+r)>>1;
		//pi(l),pi(mid),pi(r),petr
		if(calc(mid)) { l=mid;}
		else r=mid;
	}
	return l;
}
void deal(){
	ans=erfen();
}
void print(){
	printf("%lld\n",ans);
}

int main(){
	srand((int) time(0));
	scan();
	deal();
	print();
	return 0;
}