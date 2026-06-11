#include<bits/stdc++.h>
#define res register int
#define ll long long
#define inf 0x3f3f3f3f
#define N 100050
using namespace std;
int a[N],n,m,tot,ans;
inline bool cmp(res x,res y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(res i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp); 
	for(res i=1;i<=n;i++)
            if(i+1>a[i+1]){
                res j=i+1,ans=0;
                while(a[j]==i)ans^=1,j++;
                if((ans||((a[i]-i)&1)))puts("First");
                else puts("Second");
                return 0;
            }
}