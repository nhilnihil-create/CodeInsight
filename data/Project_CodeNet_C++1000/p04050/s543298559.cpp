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
typedef long long ll;
const int maxn=100010;
int n,m,A[maxn],ans[maxn],cnt;
int main() {
	n=read();m=read();
	rep(i,1,m) A[i]=read();
	if(m==1) {
		if(n==1) puts("1\n1\n1");
		else printf("%d\n2\n%d %d\n",n,1,n-1);
		return 0;
	}
	int cnt=0;
	rep(i,1,m) if(A[i]&1) cnt++;
	if(cnt>2) puts("Impossible");
	else {
		rep(i,1,m) if(A[i]&1) {swap(A[1],A[i]);break;}
		dwn(i,m,1) if(A[i]&1) {swap(A[m],A[i]);break;}
		rep(i,1,m) printf("%d%c",A[i],i==m?'\n':' ');
		cnt=0;
		rep(i,1,m) ans[++cnt]=A[i];
		ans[1]--,ans[m]++;
		if(!ans[1]) {
			printf("%d\n",cnt-1);
			rep(i,1,cnt-1) printf("%d%c",ans[i+1],i==cnt-1?'\n':' ');
		}
		else {
			printf("%d\n",cnt);
			rep(i,1,cnt) printf("%d%c",ans[i],i==cnt?'\n':' ');
		}
	}
	return 0;
}
