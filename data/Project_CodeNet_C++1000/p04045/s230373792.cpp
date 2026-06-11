#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k); 
    bool flag[15];
    for(int i=0;i<=10;i++){
        flag[i]=false;
    }
    int x;
    for(int i=1;i<=k;i++){
        scanf("%d",&x);
        flag[x]=true;
    }

    for(int i=n;;i++){
        int j=i;
        while(j>0){
            if (flag[j%10]==true){
                break;
            }
            j/=10;
        }
        if (j<=0){
            printf("%d\n",i);
            break;
        }
    }
}