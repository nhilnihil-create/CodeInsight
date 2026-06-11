#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n+5];
    long long sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }

    int c,min=1e9;
    for(int i=-100;i<=100;i++){
        c=0;
        for(int j=1;j<=n;j++){
            c+=(arr[j]-i)*(arr[j]-i);
        }
        if (c<min){
            min=c;
        }
    }
    printf("%d\n",min);

}