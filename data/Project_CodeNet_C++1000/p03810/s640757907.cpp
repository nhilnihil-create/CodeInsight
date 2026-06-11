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
int n,A[maxn];
int gcd(int a,int b) {return !b?a:gcd(b,a%b);}
int solve() {
	int a=0,b=0,is=0,sum=0;
	rep(i,1,n) {
		if(A[i]&1) a++; else b++;
		(sum+=A[i]-1)%=2;
		if(A[i]==1) is=1;
	}
//	rep(i,1,n) printf("%d%c",A[i],i==n?'\n':' ');
	if(is) return sum;
	if(b%2==1) return 1;
	else if(a!=1) return 0;
	else {
		rep(i,1,n) if(A[i]%2==1) A[i]--;
		int k=0;
		rep(i,1,n) k=gcd(k,A[i]);
		rep(i,1,n) A[i]/=k;
		return !solve();
	}
}
int main() {
	n=read();
	rep(i,1,n) A[i]=read();
	puts(solve()?"First":"Second");
	return 0;
}
