
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


int main() {
    int n;scanf("%d",&n);
    int a[n];for(int i=0;i<=n-1;i++)scanf("%d",&a[i]);
    long long int max=1,ans=a[0]-1;
    for(int i=1;i<=n-1;i++){
        if(a[i]<=max);
        else if(a[i]<=max+1)max=a[i];
        else ans+=(a[i]-1)/(max+1);
    }
    printf("%lld",ans);
    return 0;
}
