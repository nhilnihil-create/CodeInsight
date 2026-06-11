#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
int a[100000+5];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]==i) {swap(a[i],a[i+1]);sum++;}
    }
    if(a[n]==n) sum++;
    printf("%d\n",sum);
    return 0;
}
