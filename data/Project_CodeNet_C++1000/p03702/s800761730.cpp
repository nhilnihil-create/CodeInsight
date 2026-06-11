#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005],n,A,B;
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}

bool judge(long long x){
    long long temp=x*B;
    long long sub=A-B;//题目条件A一定大于B 
    long long sum=0;
    for(int i=n;i>=1;i--){
        if(a[i]>temp){
            if((a[i]-temp)%sub)
                sum+=(a[i]-temp)/sub+1;
            else
                sum+=(a[i]-temp)/sub;
        }
    }
    if(sum<=x)
        return true;
    return false;
}
int main(){
	long long r,l;
	n=read();
	A=read();
	B=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		r+=a[i]/B+1;//粗略求出最大的时候的次数 
	}
	sort(a+1,a+n+1);
	l=1;
	while(l<r){
		long long mid=(l+r)>>1;
		if(judge(mid)){
			r=mid;
		}else l=mid+1;
	}
	printf("%lld",l);
	
} 