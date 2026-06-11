//注释版
#include<bits/stdc++.h>
using namespace std;
int getint()
{
	char c;
	int ans=0,k=1;
	while(c=getchar(),c>'9' || c<'0') if(c=='-') k=-1;
	while(ans=ans*10+c-'0',c=getchar(),c>='0' && c<='9');
	return ans*k;
}
const int N=2e6+5;
int n;
int a[N];

//如果有两个相邻的数字都小于或大于二分的顶层数字，
//那么这个数字有可能一直被带到顶峰，成立
//于是可以利用单调性二分

inline bool check(int k){//从中间往两边查看有没有两个相同性质的数字（同大或同小）
    for(int i=0;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))//查看相邻两个数是否一起比k大或同小
            return 1;
        if((a[n+i]> k&&a[n+i+1]> k)||(a[n-i]> k&&a[n-i-1]> k))
            return 0;
    }
    return a[1]<=k;
}
int main()
{
	scanf("%d",&n);
	int left=0,right=(n<<1)-1;      // =n*2-1
	for(int i=1;i<=right;i++) a[i]=getint();
	int mid;
	while(left<=right){
		mid=left+right>>1;
		if(check(mid)) right=mid-1;
		else left=mid+1;
	}
	printf("%d\n",left);
	
}