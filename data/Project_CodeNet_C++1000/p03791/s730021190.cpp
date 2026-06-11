/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/
#include<stdio.h>
#define re register
const int mod=1e9+7;
int x[100005],n;
int mul(int a,int b)
{
	return 1LL*a*b%mod;
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i) scanf("%d",&x[i]);
	int pre=0,cnt=0,ans=1;
	for(re int i=1;i<=n;++i)
		if(x[i]>pre) cnt++,pre+=2;
		else ans=mul(ans,cnt+1);
	for(re int i=1;i<=cnt;++i) ans=mul(ans,i);
	printf("%d",ans);
	return 0;
}