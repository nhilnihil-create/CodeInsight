#include <iostream>
#include<vector>
#define MAXN 100001

using namespace std;

int a[MAXN];

int main()
{
    int N;
    scanf("%d",&N);
    int count2=0,count4=0;
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0&&a[i]%4!=0)
            count2++;
        if(a[i]%4==0)
            count4++;
    }
    if((3+(count4-1)*2)>=(N-(count2/2*2)))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}