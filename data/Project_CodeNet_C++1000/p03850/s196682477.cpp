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
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
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
inline char readc() {
	char c=Getchar();
	while(c!='-'&&c!='+') c=Getchar();
	return c;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=100010;
const ll inf=1ll<<60;
int n,A[maxn],tp[maxn],nxt[maxn];
ll sum[maxn],S[maxn];
int main() {
	n=read();ll res=read();
	rep(i,2,n) {
		char c=readc();A[i]=read();
		if(c=='+') tp[i]=1;
		else tp[i]=0;
	}
	S[1]=res;
	rep(i,2,n) S[i]=S[i-1]+A[i]*(tp[i]==1?1:-1);
	dwn(i,n,2) sum[i]=sum[i+1]+A[i];
	ll ans=S[n];
	dwn(i,n,1) {
		nxt[i]=nxt[i+1];
		if(tp[i]==0) nxt[i]=i;
	}
	//printf("%lld\n",ans);
	rep(i,2,n) if(!tp[i]) {
		int j=nxt[i+1];
		if(!j) break;
	//	printf("%d %d %lld\n",i,j,sum[j]+S[i]-(sum[i+1]-sum[j]));
		ans=max(ans,sum[j]+S[i]-(sum[i+1]-sum[j]));
	}
	printf("%lld\n",ans);
	return 0;
}
