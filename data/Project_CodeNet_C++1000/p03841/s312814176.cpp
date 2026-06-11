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
const int maxn=510;
const int maxm=250010;
void GG() {puts("No");exit(0);}
int ans[maxm],n,m;
pair<int,int> A[maxn];
int main() {
	n=read();m=n*n;
	rep(i,1,n) {
		int x=read();
		ans[x]=i;
		A[i]=mp(x,i);
	}
	sort(A+1,A+n+1);
	int cur=1;
	rep(i,1,n) {
		 rep(j,1,A[i].yy-1) {
		 	while(ans[cur]) cur++;
		 	ans[cur]=A[i].yy;
		 }
		 if(cur>A[i].xx) GG();
	}
	cur=m;
	dwn(i,n,1) {
		rep(j,A[i].yy+1,n) {
			while(ans[cur]) cur--;
			ans[cur]=A[i].yy;
		}
		if(cur<A[i].xx) GG();
	}
	puts("Yes");
	rep(i,1,m) printf("%d%c",ans[i],i==m?'\n':' ');
	return 0;
}
