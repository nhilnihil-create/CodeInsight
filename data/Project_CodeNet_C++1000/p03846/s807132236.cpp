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
    
    int arr[n];
    
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    reverse(arr,arr+n);
        
    int check=n-1,M=1e9+7,ans=1;
    bool poss=true;
    
    for(int i=0;i<n-1;i+=2)
    {
        if(arr[i]==arr[i+1] && arr[i]==check-i)
            ans=(ans*2)%M;
        else
        {
            poss=false;
            break;
        }
    }
    
    if(check&1^1)
    {
        if(arr[n-1]!=0)
            poss=false;
    }
    
    poss?printf("%d",ans):printf("0");
    
    return 0;
}