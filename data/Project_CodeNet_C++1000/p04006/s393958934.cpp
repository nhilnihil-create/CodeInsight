#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long int a[2010]={0};
long long int b[2010][2010]={0};
int main()
{   long long int n,x,i,j,sum,minx,temp;
    scanf("%lld %lld",&n,&x);
 
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++){
        b[i][0]=a[i];
        for(j=1;j<n;j++){
            temp=i-j;
            if(temp<=0)
                temp=n+temp;
            b[i][j]=min(b[i][j-1],a[temp]);  
        }
    }
    minx=0x3f3f3f3f3f3f3f3f;
    for(i=0;i<n;i++){
        sum=0;
        for(j=1;j<=n;j++)
            sum+=b[j][i];
        sum+=i*x;
        minx=min(sum,minx);
    }
    printf("%lld\n",minx);
    return 0;
}
