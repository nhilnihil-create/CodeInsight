#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mem(x,v) memset(x,v,sizeof(x))
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define gc getchar
#define pc putchar
#define fi first
#define se second
inline ll read(){
    ll x=0,f=1;char c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
inline void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);pc('\n');}
inline void wri(ll x){write(x);pc(' ');}
const int maxn = 2e5+233;;
//我好菜啊（题题看题解）神仙结论
int e,n,o,a[maxn];
bool solve(){ 
	if(!e) return 0;//都是偶数 
	if(e&1) return 1;//先手有优势 
	if(o!=1) return 0;
	int g=0;Rep(i,1,n)if(a[i]!=1){if(a[i]&1)a[i]--;g=__gcd(g,a[i]);}
	e=o=0;Rep(i,1,n)if(a[i]!=1){a[i]/=g;if(a[i]!=1)o+=a[i]&1,e+=!(a[i]&1);}
	return !solve();
}
int main(){
	n = read();
	Rep(i,1,n){
		a[i] = read();
		if(a[i] != 1) o += a[i] & 1,e += !(a[i] & 1);
	}
	puts(solve()?"First":"Second");
	return 0;
}
/*
wzporz 
zzdorz
clyorz
lyxorz
cljorz
zxorz
sxdorz
yzrorz
ykorz  ...9 people
qyorz ...9 people
Emmmmm这TM还想进省队，我是找死吗？
小官人，该醒醒了，你文化课凉地很呀 
 
我有一个梦想
I have a dream.
	//I'd like to get AU in NOI
	//当然，我从来没有过上面这样的不切实际的幻想
	//Ofcourse,not such unrealistic dream.
我的梦想还是比较现实的，应该是
My dream is still more realistic, it should be
有学上 
I want to go to university.

啊，普爱的耶和华呀
啊，可敬的玉皇大帝呀
啊，慈悲的如来佛祖呀
啊，无上的元始天尊呀 
赐予我力量吧 
*/ 