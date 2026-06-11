#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("%d\n",sum);
}