#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define PI acos(-1.0)
#define MOD 2520
#define E 1e-12
using namespace std;
typedef long long ll;
const int MAXN=500000+5;//最大元素个数
int n,m;//元素个数
int c[MAXN];//c[i]==A[i]+A[i-1]+...+A[i-lowbit(i)+1]
//返回i的二进制最右边1的值
int lowbit(int i)
{
    return i&(-i);
}
//返回A[1]+...A[i]的和
int sum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
//令A[i] += val
void add(int x, int val)
{
	
    while(x <= n)   //注意这里的n，是树状数组维护的长度
    {
        c[x] += val;
        x += lowbit(x);
    }
}
struct node
{
	int l,r;
}a[MAXN];
bool cmp(node x,node y)
{
	return x.r-x.l<y.r-y.l;
}
int main()
{

    while(scanf("%d%d",&m,&n)!=-1)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a+1,a+m+1,cmp);
		
		int j=0;
		for(int d=1;d<=n;d++)
		{
			int temp=0;
			for(int i=d;i<=n;i+=d)
			{
				temp+=sum(i);
			}
			printf("%d\n",temp+m-j)  ;
			
			while(j<m&&a[j+1].r-a[j+1].l<=d)
			{
				add(a[j+1].l,1);
				add(a[j+1].r+1,-1);
				j++;
			}
			
		}
    }
    return 0;
}
