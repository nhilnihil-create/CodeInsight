#include<bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
#define MAX 200005
#define MOD 1000000000
#define NINF -1000000000000000000
int main()
{
    int n,i,j;
    scanf("%d",&n);
    pair<int,int> arr[n];
    for(i=0;i<n;i++)
    {
        arr[i].second=i;
        scanf("%d",&arr[i].first);
    }
    sort(arr,arr+n);
    int ans=0;
    for(i=0;i<n;i++)
    {
        if((i+arr[i].second)%2) ans++;
    }
    ans=ans/2;
    printf("%d",ans);
    return 0;
}
