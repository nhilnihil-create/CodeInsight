///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//                       _oo0oo_                         //
//                      o8888888o                        //
//                      88" . "88      ------ hzt1       //
//                      (| -_- |)                        //
//                      0\  =  /0                        //
//                    ___/`---'\___                      //
//                  .' \|     |// '.                     //
//                 / \|||  :  |||// \                    //
//                / _||||| -:- |||||- \                  //
//               |   | \  -  /// |     |                 //
//               | \_|  ''\---/''  |_/ |                 //
//               \  .-\__  '-'  ___/-. /                 //
//             ___'. .'  /--.--\  `. .'___               //
//          ."" '<  `.___\_<|>_/___.' >' "".             //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |           //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /           //
//     =====`-.____`.___ \_____/___.-`___.-'=====        //
//                       `=---='                         //
//                                                       //
//                                                       //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~       //
//                                                       //
//                 God-He Bless All.                     //
//           This Code Will Never Explode.               //
//                                                       //
//                                                       //
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
const int Size=1<<16;
char buffer[Size],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,Size,stdin);
        tail=(head=buffer)+l;
    }
    if(head==tail) return -1;
    return *head++;
}
inline int read() {
    int x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
const int maxn=100010;
int n,m,pa[maxn],d[maxn],siz[maxn],cnt[maxn];
int findset(int x) {
	if(x==pa[x]) return x;
	int res=findset(pa[x]);
	d[x]+=d[pa[x]];
	return pa[x]=res;
}
int main() {
	n=read();m=read();
	rep(i,1,n) pa[i]=i,siz[i]=1;
	rep(i,1,m) {
		int x,y;
		int u=findset(x=read()),v=findset(y=read());
		if(u==v) {
		//	printf("%d %d %d %d\n",x,y,d[x],d[y]);
			if((d[x]%2)==(d[y]%2)) cnt[v]++;
		}
		else {
			pa[u]=v;d[u]=d[x]+d[y]+1;//printf("%d -> %d\n",u,v);
			siz[v]+=siz[u];cnt[v]+=cnt[u]+1;
		}
	}
	ll a=0,b=0,c=0;
	rep(i,1,n) if(findset(i)==i) {
		if(siz[i]==1) c++;
		else if(cnt[i]+1==siz[i]) a++;
		else b++;
	}
	ll ans=0;
	ans+=2*a+b+2*a*(a-1)+2*b*a+b*(b-1);
	int cur=n-c;
	rep(i,1,c) {
		ans+=1+2*cur;
		cur++;
	}
	printf("%lld\n",ans);
	return 0;
}