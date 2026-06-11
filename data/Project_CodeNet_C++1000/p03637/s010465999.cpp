#include<iostream>
#include<ctype.h>
#include<cmath>
#include<queue>
#define MAXN 10001

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int ct_2=0,ct_4=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%4==0)
            ct_4++;
        else{
            if(a[i]%2==0)
                ct_2++;
        }
    }
    if(ct_2>=2)
        n-=ct_2-1;
    if(n<=(3+(ct_4-1)*2)&&ct_4>=1||n==1)
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
