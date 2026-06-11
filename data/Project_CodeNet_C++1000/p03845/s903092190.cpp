#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n;
    
    scanf("%d",&n);
    
    int arr[n],sum=0;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    
    int m;
    
    scanf("%d",&m);
    
    for(int i=0;i<m;i++)
    {
        int x,y;
        
        scanf("%d%d",&x,&y);
        
        x--;
        
        printf("%d\n",sum-arr[x]+y);
    }
    
    return 0;
}