#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int n,mod=1e9+7,ans=1;
    bool poss=true;
    
    scanf("%d",&n);
    
    int diffs[n]={0};
    
    for(int i=0;i<n;i++)
    {
        int x;
        
        scanf("%d",&x);
        
        diffs[x]++;
    }
    
    if(n&1^1)
    {
        for(int i=1;i<n;i+=2)
        {
            if(diffs[i]==2)
                ans=(ans*2)%mod;
            else
            {
                poss=false;
                break;
            }
        }
    }
    else
    {
        if(diffs[0]!=1)
            poss=false;
        else
        {
            for(int i=2;i<n;i+=2)
            {
                if(diffs[i]==2)
                    ans=(ans*2)%mod;
                else
                {
                    poss=false;
                    break;
                }
            }
        }
    }
    
    poss?printf("%d",ans):printf("0");

    return 0;
}